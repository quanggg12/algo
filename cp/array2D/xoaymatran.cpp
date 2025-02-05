#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    int a[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            swap(a[i][j], a[i][n - j - 1]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
