#include <bits/stdc++.h>
using namespace std;

bool isSafe(int arr[10][10], int r, int c, int n) {
    for (int i = 0; i < c; i++) {
        if (arr[r][i]) return true;
    }
    
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j]) return true;
    }
    
    for (int i = r, j = c; i < n && j >= 0; i++, j--) {
        if (arr[i][j]) return true;
    }
    return false;
}

void Print(int arr[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }    
}

bool solve(int n, int arr[10][10], int c, vector<int>& vec, vector<vector<int>>& sol) {
    if (c == n) {
        //Print(arr, n);
        //cout << endl;
        sol.push_back(vec);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (!isSafe(arr, i, c, n)) {
            arr[i][c] = 1;
            vec.push_back(i+1);
            res = solve(n, arr, c+1, vec, sol) || res;
            arr[i][c] = 0;
            vec.pop_back();
        }
    }
    return res;
}

void solve(int n) {
    int arr[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    vector<vector<int>> sol;
    vector<int>vec;
    solve(n, arr, 0, vec, sol);
    
    for (int i = 0; i < sol.size(); i++) {
        for (int u : sol[i]) cout << u << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
	return 0;
}
