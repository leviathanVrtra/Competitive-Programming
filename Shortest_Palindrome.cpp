// https://leetcode.com/problems/shortest-palindrome/
// solution using Manacher's algorithm
string shortestPalindrome(string s) {
    int n=s.size();

    // manacher's algo
    vector<int> d1(n, 0), d2(n, 0);

    // first for odd length string
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], (r - i + 1));
        while ((i - k) >= 0 && (i + k) < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if((i + k) > r) {
            l = i - k;
            r = i + k;
        }
    }

    // even length string
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], (r - i + 1));
        while((i - k - 1) >= 0 && (i + k) < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if((i + k) > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    // now find the maximum length palindromic substring starting from index 0
    int x = 1;
    for(int i = 1; i < n; i++) {
        if(d1[i] == i + 1)
            x = max(x, (2 * d1[i] - 1));
    }
    string t1, t2;
    for(int i = n - 1; i >= x; i--) t1.push_back(s[i]);
    t1 += s;

    x = 0;
    for(int i = 1; i < n; i++) {
        if(d2[i] == i)
            x = max(x, (2 * d2[i]));
    }
    for(int i = n - 1; i >= x; i--) t2.push_back(s[i]);
    t2 += s;

    if(t1.size() <= t2.size())
        return t1;
    return t2;
}