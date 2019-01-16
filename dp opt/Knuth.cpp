#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

// Problema: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1860
const int MAXM = 1e3+10; const ll INF = 1e18;
int cost[MAXM], opt[MAXM][MAXM];
ll dp[MAXM][MAXM];

int main() {
	fastio;
	
    int n, m;
    while (cin >> n >> m) {
        cost[0] = 0;
        forsn(i, 1, m+1) {
            int a; cin >> a;
            cost[i] = a;
        }
        cost[m+1] = n;
        m += 2;

        // Casos base
        forn(i, m-1) dp[i][i+1] = 0;
        forn(i, m-2) opt[i][i+2] = i+1, dp[i][i+2] = cost[i+2]-cost[i];

        // Casos recursivos
        forsn(len, 3, m+1) {
            forn(l, m-len) {
                int r = l+len;

                dp[l][r] = INF;
                forsn(k, opt[l][r-1], opt[l+1][r]+1) {
                    ll val = dp[l][k] + dp[k][r] + cost[r] - cost[l];
                    if (val < dp[l][r]) {
                        dp[l][r] = val;
                        opt[l][r] = k;
                    }
                }
            }
        }

        cout << dp[0][m-1] << endl;
    }    
	
	return 0;
}
