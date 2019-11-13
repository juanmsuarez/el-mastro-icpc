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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MOD = 1e9 + 7;
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }

const int N = 5e3;

int dp[N][N + 1];
int diag[N][N + 1];

int main() {
	fastio;
	
    int s, b; cin >> s >> b;
   
    forn(stacks, s + 1) dp[0][stacks] = 1;

    forsn(blocks, 1, b) {
        dp[blocks][0] = 0;

        diag[blocks][0] = 0;
        forsn(k, 1, blocks + 1) {
            int nblocks = blocks - k, nstacks = k;
            diag[blocks][k] = add(diag[blocks][k - 1], dp[nblocks][nstacks]);
        }

        forsn(stacks, 1, s + 1) {
            dp[blocks][stacks] = add(dp[blocks][stacks - 1], diag[blocks][min(blocks, stacks)]);
        }
    }
   
    cout << dp[b - s][s] << endl;
	
	return 0;
}
