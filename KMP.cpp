#include <bits/stdc++.h>
using namespace std;

void getLps(string str, vector<int>& lps) {
    int i = 1, len = 0;
    int n = str.size();

    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
}

void kmp(string pat, string text) {
    int m = pat.size();
    int n = text.size();

    vector<int>lps(m, 0);

    getLps(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at idx " << (i - j) << endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

/*
// https://leetcode.com/problems/shortest-palindrome/
// Longest palindromic prefix
void shortestPalindrome(string str) {
    string temp = str + '#';
    reverse(str.begin(), str.end());
    temp += str;

    int n = temp.length();
    vector<int>lps(n, 0);

    int idx = getLps(str, lps);
    
    string tmp = str.substr(idx, (n - idx + 1));
    reverse(tmp.begin(), tmp.end());
    tmp = tmp + str;
    
    cout << tmp << endl;
}
*/
/*
ABABDABACDABABCABAB
ABABCABAB
*/

int main()
{
    string pat, text;
    cin >> text >> pat;
    kmp(pat, text);
    return 0;
}