#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m, a[100][100], s, t, u, v;
ll f[100][100];

void nhap() {
    cin >> n >> m >> s >> t >> u >> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void loang(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 1) {
            loang(x, y);
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    nhap();
    loang(s, t);
    if (a[u][v] == 0) cout << "YES";
    else cout << "NO";
    return 0;
}