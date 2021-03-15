#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000009

int strLen(const char *str) {
    int len = 0;
    while (*str) {
        len++;
        *str++;
    }
    return len;
}

struct TrieNode {
    struct Trie {
        int prefix;
        int cnt;
        int child[26];
        bool isEnd;
    };
    Trie trie[MAX_SIZE];
    int root, poolIdx;

    int newNode() {
        poolIdx++;
        for (int i = 0; i < 26; i++) {
            trie[poolIdx].child[i] = '\0';
        }
        trie[poolIdx].cnt = 0;
        trie[poolIdx].isEnd = false;
        trie[poolIdx].prefix = 0;

        return poolIdx;
    }

    void Init() {
        poolIdx = 0;
        root = newNode();
    }

    void Insert(const char *key) {
        int ptr = root;
        int len = strLen(key);

        for (int i = 0; i < len; i++) {
            int idx = key[i] - 'a';
            if (trie[ptr].child[idx] == '\0') {
                trie[ptr].child[idx] = newNode();
            }
            ptr = trie[ptr].child[idx];
            trie[ptr].prefix++;
        }
        trie[ptr].cnt++;
        trie[ptr].isEnd = true;
    }

    bool Search(const char *key) {
        int ptr = root;
        int len = strLen(key);

        for (int i = 0; i < len; i++) {
            int idx = key[i] - 'a';
            if (trie[ptr].child[idx] == '\0') {
                return false;
            }
            ptr = trie[ptr].child[idx];
        }
        return trie[ptr].isEnd;
    }

    void Delete(const char *key) {
        if (!Search(key)) {
            return;
        }
        int ptr = root;
        int len = strLen(key);
        int prev = ptr;
        for (int i = 0; i < len; i++) {
            int idx = key[i] - 'a';
            prev = ptr;
            ptr = trie[ptr].child[idx];
            trie[ptr].prefix--;

            if (trie[ptr].prefix == 0) {
                trie[prev].child[idx] = '\0';
                if (trie[ptr].isEnd == true) {
                    trie[ptr].isEnd = false;
                }
                return;
            }
        }
        trie[ptr].cnt--;
        if (trie[ptr].cnt == 0 && trie[ptr].isEnd == true) {
            trie[ptr].isEnd = false;
        }
    }

    int CntPrefix(const char *key) {
        int ptr = root;
        int len = strLen(key);

        for (int i = 0; i < len; i++) {
            int idx = key[i] - 'a';
            if (trie[ptr].child[idx] == '\0') {
                return 0;
            }
            ptr = trie[ptr].child[idx];
        }
        return trie[ptr].prefix;
    }
};
TrieNode root;

int main()
{

    return 0;
}