#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15][15];

bool isSafe(int r, int c, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[r][i] == num) return false;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][c] == num) return false;
    }
    r = r - (r % 3);
    c = c - (c % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i+r][i+c] == num) return false;
        }
    }
    return true;
}

bool isFull(int &r, int &c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                r = i, c = j;
                return true;
            }
        }
    }
    return false;
}

bool solve() {
    int r, c;
    if (!isFull(r, c)) {
        return true;
    }
    
    for (int k = 1; k < 10; k++) {
        if(isSafe(r, c, k)) {
            arr[r][c] = k;
            if (solve()) {
                return true;
            }
            arr[r][c] = 0;
        }
    }
    return false;
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    solve();
    Print();
	return 0;
}
