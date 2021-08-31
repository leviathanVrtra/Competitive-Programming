// https://leetcode.com/problems/word-search/

class Solution {
public:
    int n, m, sz;
    int X[4] = {-1, 0, 1, 0};
    int Y[4] = {0, 1, 0, -1};
    
    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    bool dfs(vector<vector<char>>& bd, string wd, int i, int j, int idx) {
        if (bd[i][j] != wd[idx]) {
            return false;
        }
        if (idx == sz - 1) {
            return true;
        }
        char tmp = bd[i][j];
        bd[i][j] = '$';
        bool flg = false;
        for (int k = 0; k < 4; k++) {
            int dx = i + X[k];
            int dy = j + Y[k];
            if (isValid(dx, dy) && bd[dx][dy] != bd[i][j]) {
                flg = flg || dfs(bd, wd, dx, dy, idx + 1);
            }
        }
        bd[i][j] = tmp;
        return flg;
    }
    
    bool exist(vector<vector<char>>& bd, string wd) {
        n = bd.size();
        m = bd[0].size();
        sz = wd.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bd[i][j] == wd[0]) {
                    if (dfs(bd, wd, i, j, 0) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    /*
    // Method No - 02
    // Using Trie DS
    #define MAX_SIZE 10009

    struct Trie {
        int child[123];
        bool isEnd;
    };
    Trie trie[MAX_SIZE];
    int root, poolIdx;

    int newNode() {
        poolIdx++;
        for (int i = 0; i < 123; i++) {
            trie[poolIdx].child[i] = '\0';
        }
        trie[poolIdx].isEnd = false;

        return poolIdx;
    }

    void Init() {
        poolIdx = 0;
        root = newNode();
    }

    void Insert(string key) {
        int ptr = root;
        int len = key.size();

        for (int i = 0; i < len; i++) {
            int idx = key[i];
            if (trie[ptr].child[idx] == '\0') {
                trie[ptr].child[idx] = newNode();
            }
            ptr = trie[ptr].child[idx];
        }
        trie[ptr].isEnd = true;
    }

    bool dfs(int ptr, vector<vector<char>>& bd, int i, int j) {
        int val = bd[i][j];
        
        if (trie[ptr].child[val] == '\0') return false;
        
        ptr = trie[ptr].child[val];
        if (trie[ptr].isEnd) return true;
        
        char tmp = bd[i][j];
        bd[i][j] = '$';
        
        bool flg = false;
        for (int k = 0; k < 4; k++) {
            int dx = i + X[k];
            int dy = j + Y[k];
            if (isValid(dx, dy) && bd[dx][dy] != bd[i][j]) {
                int c = bd[dx][dy];
                if (trie[ptr].child[c]) {
                    flg = flg || dfs(ptr, bd, dx, dy);
                }
            }
        }
        
        bd[i][j] = tmp;
        return flg;
    }  
    
    bool exist(vector<vector<char>>& bd, string wd) {
        n = bd.size();
        m = bd[0].size();
        sz = wd.size();
        Init();
        Insert(wd);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = bd[i][j];
                if (trie[root].child[c] && dfs(root, bd, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    */
};