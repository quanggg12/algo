#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge(int a[], int l, int m, int r){
	int n1 = m - l + 1, n2 = r - m;
	int L[n1], R[n2];
	for(int i = 0; i < n1; i++) L[i] = a[l+i];
	for(int i = 0; i < n2; i++) R[i] = a[m + i + 1];
	int i = 0, j = 0, k = l;
	while(i < n1 and j < n2){
		if(L[i] <= R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while(i < n1) a[k++] = L[i++];
	while(j < n2) a[k++] = R[j++];
}

void mergesort(int a[], int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, m, r);
	}
}


int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	mergesort(a, 0, n - 1);
	for(int x : a) cout << x << " ";
    return 0;
}

