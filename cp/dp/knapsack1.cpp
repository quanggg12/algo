#include <bits/stdc++.h>
#define ll long long

using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_d

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - weights[i - 1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}
