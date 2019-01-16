#include <bits/stdc++.h>
using namespace std;

const int N = 1004;
const double eps = 1e-7;
double dp[N];
int ans[N];

int main(){
	int k, q, d = 1;
	cin >> k >> q;
	dp[0] = 1;
    cerr << dp[0] << " ";
    for(int x = 1; x <= k; x++)cerr << dp[x] << " ";
    cerr << endl;
	for(int n = 1; d <= 1000; ++n){
		for(int x = k; x > 0; --x){
            if(n<5)cerr << n << " " <<x << " " << x*dp[x] << " " << (k-x+1) * dp[x-1] <<endl;
			dp[x] = (x * dp[x] + (k - x + 1) * dp[x - 1]) / k;
            if(n<5)cerr << dp[x] << endl;
		}
		if(n<=10){
            cerr << dp[0] << " ";
            for(int x = 1; x <= k; x++)cerr << dp[x] << " ";
            cerr << endl;
        }
		while(d <= 1000 && 2000 * dp[k] >= (d - eps)){
			ans[d] = n;
			d++;
		}
		dp[0] = 0;
	}
	while(q--){
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
}
