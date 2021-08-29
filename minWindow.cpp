//https://leetcode.com/problems/minimum-window-substring/
// Using Sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if (n < m || m == 0) return "";
        if (n == m && s == t) return t;
        
        vector<int>freq(256, 0);
        int cnt = 0;
        for (int x : t) {
            if (freq[x] == 0) cnt++;
            freq[x]++;
        }
        
        int i = 0, j = 0;
        int idx = 0, mnLen = 999999;
        
        while (j < n) {
            freq[s[j]]--;
            if (freq[s[j]] == 0) cnt--;
            while (cnt == 0) {
                if (mnLen > (j - i + 1)) {
                    mnLen = j - i + 1;
                    idx = i;
                }
                freq[s[i]]++;
                if (freq[s[i]] == 1) cnt++;
                i++;
            }
            j++;
        }
        
        if (mnLen == 999999) return "";
        string res = s.substr(idx, mnLen);
        return res;
    }
};