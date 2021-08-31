// https://leetcode.com/problems/word-search-ii/
// Word Search solution using DFS
#include <bits/stdc++.h>
using namespace std;

int n, m, num;
char word[105][105];
vector<string>dict;
vector<string>res;

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool findWord(int i, int j, int idx, string str) {
    if (!isValid(i, j) || (word[i][j] == '*') || (word[i][j] != str[idx])) {
        return false;
    }
    if (idx == (str.size() - 1)) {
        return true;
    }
    char curr = word[i][j];
    word[i][j] = '*';
    bool flg = false;
    for (int k = 0; k < 4; k++) {
        int dx, dy;
        dx = i + X[k];
        dy = j + Y[k];
        if (isValid(dx, dy) && (word[dx][dy] == str[idx+1])) {
            flg = flg || findWord(dx, dy, idx+1, str);
        }
    }
    word[i][j] = curr;
    return flg;
}

void solve() {
    for (int k = 0; k < num; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dict[k][0] == word[i][j]) {
                    if (findWord(i, j, 0, dict[k])) {
                        res.push_back(dict[k]);
                        j = m;
                        i = n;
                    }
                }
            }
        }
    }

    //Uncomment the following code if output words are unique and sorted
    /*
    set<string>st;
    for (int i = 0; i < res.size(); i++) {
        string ss = res[i];
        st.insert(ss);
    }
    res.clear();
    set<string>::iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        string ss = *it;
        res.push_back(ss);
    }
    */
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