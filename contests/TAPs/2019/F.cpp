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

const int MOD = 1e9+7;

int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }

const int N = 7, M = 50, K = 4;
const int C = 1<<(2*N);

int get(int col, int pos) { return (col >> (2*pos)) & (K - 1); }

bool valid[C];
vi next_valid[C];

int n, m, k;
int def[N][M];

bool consistent[C][M];

void precomp() {
    forn(col, C) {
        bool can = true;
        int pre = -1;
        forn(i, n) {
            if (get(col, i) >= k || get(col, i) == pre) can = false;
            pre = get(col, i);
        }
        forsn(i, n, N) if (get(col, i) != 0) can = false;

        if (can) valid[col] = true;
    }

    forn(col1, C) if (valid[col1]) forn(col2, C) if (valid[col2]) {
        bool can = true;
        forn(i, n) if (get(col1, i) == get(col2, i)) can = false;

        if (can) next_valid[col1].pb(col2); 
    }

    forn(col, C) if (valid[col]) forn(j, m) {
        bool can = true;
        forn(i, n) if (def[i][j] != -1 && def[i][j] != get(col, i)) can = false;

        if (can) consistent[col][j] = true;
    }
}

int memo[M][C];

int dp(int filled, int prev_col) {
    if (filled == m) return 1;

    int &res = memo[filled][prev_col];
    if (res != -1) return res;

    res = 0;
    for (int col : next_valid[prev_col]) if (consistent[col][filled]) 
        res = add(res, dp(filled + 1, col));

    return res;
}

int main() {
	fastio;

    cin >> n >> m >> k;
    forn(i, n) forn(j, m) {
        char c; cin >> c;
        if (c == '-') def[i][j] = -1;
        else def[i][j] = c - '1';
    }

    precomp();	
    fill(memo[0], memo[M], -1);

    int ans = 0; 
    forn(col, C) if (valid[col] && consistent[col][0]) ans = add(ans, dp(1, col));
    cout << ans << endl;
	
	return 0;
}
