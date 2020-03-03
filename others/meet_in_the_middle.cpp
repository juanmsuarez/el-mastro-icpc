// Technique used to determine the maximum sum subset having sum less than or equal S in O(2^(n/2)*n).

#include <bits/stdc++.h> 
using namespace std;

#define forn(i,n) for(int i = 0 ; i < int(n) ; i++)
typedef long long int  ll;

const int N = 1 << 25; // Array size must be at most 50
ll a[] = {3,34,4,12,5,2}, X[N], Y[N];

void subset_sums(ll x[], int n, int s){
	for(int i = 0; i < (1<<n); i++)
		forn(j,n) if(i & (1<<j)) x[i] += a[j+s];
}

int max_subset_sum(int n, int m){
	subset_sums(X,n/2,0);
	subset_sums(Y,n-n/2,n/2);
	int sz_x = 1<<(n/2), sz_y = 1<<(n-n/2); 
	sort(Y,Y+sz_y);
	ll M = 0;
	forn(i,sz_x) if(X[i] <= m){ // if n/2 is zero sz_x will be one as X has an empty subset
		int p = lower_bound(Y,Y+sz_y,m-X[i])-Y;
		if(p == sz_y || Y[p] != m-X[i]) p--;    // p can't be zero as Y has an empty subset
		M = max(M, X[i] + Y[p]);
	}
	return M;
}

int main(){
	int n = sizeof(a) / sizeof(a[0]), m = 10;
	cout << max_subset_sum(n,m) << endl; 
	return 0;
}
