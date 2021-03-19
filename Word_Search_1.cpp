// Word Search solution using Trie Data Structure
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000009

char word[105][105];
vector<string>dict;
int n, m, num;

struct TrieNode {
    struct Trie {
        int child[26];
        bool isEnd;
    };
    Trie trie[MAX_SIZE];
    int root, poolIdx;

    int newnode() {
        poolIdx++;
        for (int i = 0; i < 26; i++) {
            trie[poolIdx].child[i] = 0;
        }
        trie[poolIdx].isEnd = false;
        return poolIdx;
    }

    void Init() {
        poolIdx = 0;
        root = newnode();
    }

    void Insert(const string str) {
        int ptr = root;
        int len = str.size();

        for (int i = 0; i < len; i++) {
            int idx = str[i] - 'a';
            if (trie[ptr].child[idx] == 0) {
                trie[ptr].child[idx] = newnode();
            }
            ptr = trie[ptr].child[idx];
        }
        trie[ptr].isEnd = true;
    }
};
TrieNode root;
vector<string>res;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void findWord(int i, int j, string str, int ptr) {
    if (!isValid(i, j)) return;
    if (word[i][j] == '*') return;

    if (root.trie[ptr].child[word[i][j] - 'a'] != 0) {
        str += word[i][j];
        ptr = root.trie[ptr].child[word[i][j] - 'a'];
        if (root.trie[ptr].isEnd == true) {
            res.push_back(str);
        }
        char curr = word[i][j];
        word[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            int dx, dy;
            dx = i + X[k];
            dy = j + Y[k];
            if (isValid(dx, dy)) {
                findWord(dx, dy, str, ptr);
            }
        }
        word[i][j] = curr;
    }
}

void solve() {
    root.Init();
    for (int i = 0; i < dict.size(); i++) {
        root.Insert(dict[i]);
    }
    int ptr = root.root;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            findWord(i, j, "", ptr);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++) {
        string str;
        cin >> str;
        dict.push_back(str);
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> word[i][j];
        }
    }
    solve();
    return 0;
}
/*
4
geeks
for
quiz
gee
3 3
g k s
e e z
q u i
-----------
4
oath
pea
eat
rain
4 4
o a a n
e t a e
i h k r
i f l v
------------
2
geeks
abcfihgde
3 3
a b c
d e f
g h i
*/