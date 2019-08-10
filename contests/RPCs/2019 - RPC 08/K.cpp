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

const int N = 2500+1, M = 1e9+7;
int comb[N][N];

int add(int a, int b) { return a + b >= M ? a + b - M : a+b; }
int sub(int a, int b) { return a - b < 0 ? a - b + M : a-b; }
int mul(int a, int b) { return (ll)a*b%M; }
int pot(int b, int e){ // O(log e)
	if (e == 0) return 1;
	int q = pot(b, e/2); q = mul(q, q);
	return (e % 2 == 1 ? mul(b, q) : q);
}

int main() {
	fastio;

    forn(i, N) {
        comb[i][0] = comb[i][i] = 1;
        forsn(k,1,i) comb[i][k] = add(comb[i-1][k], comb[i-1][k-1]);
    }
	
    int n, k; cin >> n >> k;

    vi dp(k+1);
    forsn(colors, 2, k+1) {
        int &act = dp[colors];

        act = mul(colors, pot(colors-1, n-1)); 
        forn(prev, colors) act = sub(act, mul(comb[colors][prev], dp[prev]));
    }

    cout << dp[k] << endl;
	
	return 0;
}
