#include <bits/stdc++.h>
using namespace std;

string preProcess(const string &s) {
    const int n = s.size();
    if(n == 0) return "^$";
    string res = "^";
    for(int i = 0; i < n; i++) {
        res += "#" + s.substr(i,1);
    }
    res += "#$";
    return res;
}

string longestPalindrome(string s) {
    string str = preProcess(s);
    const int n = str.size();
    int c = 0, r = 0, max = 0, idx = 0;
    int p[n];
    for(int i = 1; i < (n - 1); i++) {
        int j = 2 * c - i;
        int k = (i < r) ? min(p[j], r - i) : 0;

        while(((i - 1 - k) >= 0) && ((i + 1 + k) < n) && (str[i - 1 - k] == str[i + 1 + k])) k++;
        
        p[i] = k;
        if(i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        
        if(p[i] > max) {
            max = p[i];
            idx = i;
        }
    }

    return s.substr((idx - max - 1)/2,max);
}

// abaxabaxabb
int main()
{
    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;
    return 0;
}