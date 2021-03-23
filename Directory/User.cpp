#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define MAX_DIR 50009
#define MAX_CHILD 31
#define ROOT 0
 
#include <iostream>
using namespace std;
 
struct Directory {
	int cnt;
	int parent;
	int child[MAX_CHILD];
	unsigned int hash;
};
Directory dirs[MAX_DIR];
int last;
 
void init(int n) {
	last = ROOT;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_CHILD; j++) {
			dirs[i].child[j] = 0;
		}
		dirs[i].cnt = 0;
		dirs[i].parent = 0;
		dirs[i].hash = 0;
	}
}
 
void Print() {
	for (int i = 0; i <= last; i++) {
		cout << "Lst: " << i << endl;
		cout << "Chld: ";
		for (int j = 0; j < MAX_CHILD; j++) {
			cout << dirs[i].child[j] << " ";
		}
		cout << endl;
		cout << "C: " << dirs[i].cnt << endl;
		cout << "H: " << dirs[i].hash << endl;
		cout << "P: " << dirs[i].parent << endl;
	}
	cout << "=============================================================================" << endl;
}
 
int findHash(char **str) {
	int hs = 0;
	while (**str && **str != '/') {
		hs = (hs << 5) + (**str - 'a' + 1);
		(*str)++;
	}
	return hs;
}
 
int findDir(char *path, int *child) {
	int ptr = ROOT;
	int i = 0;
	for (++path; *path && *(path + 1); ++path) {
		int hs = findHash(&path);
		for (i = 0; dirs[dirs[ptr].child[i]].hash != hs; i++);
		ptr = dirs[ptr].child[i];
	}
	*child = i;
	return ptr;
}
 
void addCnt(int ptr, int cnt) {
	while (ptr != ROOT) {
		dirs[ptr].cnt += cnt;
		ptr = dirs[ptr].parent;
	}
	dirs[ptr].cnt += cnt;
}
 
void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	int i = 0;
	int dd = findDir(path, &i);
 
	for (i = 0; dirs[dd].child[i]; i++);
	dirs[dd].child[i] = ++last;
	dirs[last].hash = findHash(&name);
	dirs[last].cnt = 0;
	dirs[last].parent = dd;
	addCnt(dd, 1);
	//Print();
}
 
void cmd_rm(char path[PATH_MAXLEN + 1]) {
	int i = 0, j;
	int dd = findDir(path, &i);
 
	for (j = i; dirs[dirs[dd].parent].child[j]; j++);
	dirs[dirs[dd].parent].child[i] = dirs[dirs[dd].parent].child[j - 1];
	dirs[dirs[dd].parent].child[j - 1] = 0;
 
	addCnt(dirs[dd].parent, (-1 * (dirs[dd].cnt + 1)));
	//Print();
}
 
void cpySubtree(int ss, int dd) {
	int ptr = ++last;
	dirs[last].parent = dd;
	dirs[last].hash = dirs[ss].hash;
	dirs[last].cnt = dirs[ss].cnt;
	int i = 0;
	for (i = 0; dirs[dd].child[i]; i++);
	dirs[dd].child[i] = last;
	for (i = 0; dirs[ss].child[i]; i++) {
		cpySubtree(dirs[ss].child[i], ptr);
	}
}
 
void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int i = 0;
	int ss = findDir(srcPath, &i);
	int dd = findDir(dstPath, &i);
	addCnt(dd, dirs[ss].cnt + 1);
 
	cpySubtree(ss, dd);
	//Print();
}
 
void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int i = 0, j;
	int ss = findDir(srcPath, &i);
	for (j = i; dirs[dirs[ss].parent].child[j]; j++);
	dirs[dirs[ss].parent].child[i] = dirs[dirs[ss].parent].child[j - 1];
	dirs[dirs[ss].parent].child[j - 1] = 0;
	addCnt(dirs[ss].parent, (-1 * (dirs[ss].cnt + 1)));
 
	int dd = findDir(dstPath, &i);
	for (i = 0; dirs[dd].child[i]; i++);
	dirs[dd].child[i] = ss;
	dirs[ss].parent = dd;
	addCnt(dd, (dirs[ss].cnt + 1));
	//Print();
}
 
int cmd_find(char path[PATH_MAXLEN + 1]) {
	int i = 0;
	int dd = findDir(path, &i);
	//cout << "Ans: " << dirs[dd].cnt << endl;
	return (dirs[dd].cnt);
}
