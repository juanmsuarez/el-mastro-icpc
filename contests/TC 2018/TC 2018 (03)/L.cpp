#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const double eps = 1e-9;

int main() {
    fastio;

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		double a[n], b[n];
		int dp[n];
		forn(i,n) cin >> a[i] >> b[i];
		forn(i,n) dp[i] = 1;
		dforsn(i,0,n-1) 
            forsn(j,i+1,n) 
                if(a[i] < a[j]-eps && b[i] > b[j]+eps && dp[j]+1 > dp[i]) 
                    dp[i] = dp[j]+1;
        int ans = 0;
        forn(i, n) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
    return 0;
}
