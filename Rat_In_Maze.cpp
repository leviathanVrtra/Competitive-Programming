#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15][15];
int visit[15][15];

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

vector<string>vec;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void solve(int i, int j, string res) {
    if (!isValid(i, j)) return;
    if (i == n-1 && j == n-1) {
        vec.push_back(res);
        //cout << res << endl;
        return;
    }
    visit[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int dx, dy;
        dx = i + X[k];
        dy = j + Y[k];
        if (isValid(dx, dy) && !visit[dx][dy] && (arr[dx][dy] == 1)) {
            if (k == 0) res += "U";
            if (k == 1) res += "R";
            if (k == 2) res += "D";
            if (k == 3) res += "L";
            solve(dx, dy, res);
            res.erase(res.size() - 1);  
        }    
    }
    visit[i][j] = 0;
}

void solve() {
    if (arr[0][0] == 0 || arr[n-1][n-1] == 0) {
        vec.push_back("-1");
        return;
    }
    
    solve(0, 0, "");
    
    if (vec.size() == 0) vec.push_back("-1");
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            visit[i][j] = 0;
        }
    }
    solve();
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
	return 0;
}
