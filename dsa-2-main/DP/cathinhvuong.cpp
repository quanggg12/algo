#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c[100][100], p[100][100];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        c[i][1] = i;
        p[i][1] = 1;
   }
   for(int j = 1; j <= m; j++){
        c[1][j] = j;
        p[1][j] = -1;
   }

   for(int i = 2; i <= n; i++){
    for(int j = 2; j <= m; j++){
        c[i][j] = i * j;
        for(int k = 1; k <= i/2; k++){
            if(c[i][j] > c[k][j] + c[i - k][j]){
                c[i][j] = c[k][j] + c[i - k][j];
                p[i][j] = k;
            }
        }
        for(int k = 1; k <= j/2; k++){
            if(c[i][j] > c[i][k] + c[i][j - k]){
                c[i][j] = c[i][k] + c[i][j - k];
                p[i][j] = -k;
            }
        }
    }
   }
   cout << "so hv it nhat: " << c[n][m];
   return 0;
}

// int dp[501][501]; 

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int m, n;
//     cin >> m >> n;

//    
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (i == j) {
//                 dp[i][j] = 1; 
//             } else {
//                 dp[i][j] = INT_MAX; 

//                 // Cat ngang
//                 for (int k = 1; k < i; k++) {
//                     dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
//                 }

//                 // Cat dọc
//                 for (int k = 1; k < j; k++) {
//                     dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
//                 }
//             }
//         }
//     }

//     cout << dp[m][n];

//     return 0;
// }
