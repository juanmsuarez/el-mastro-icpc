#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 1e4+10, MAXWH = 100+10, MOD = 1e9+7;

int N, W, H, memo[MAXN][MAXWH][2];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int dp(int n, int w, bool eq) {
    if (w == W) return !eq;
    
    int &res = memo[n][w][eq];
    if (res != -1) return res;
    res = 0;

    forn(y, min(n, H)+1)
        add(res, dp(n-y, w+1, eq && (w == 0 || y == (N-n)/(w))));

    return res;
}

int main() {
    fastio;

    while (cin >> N >> W >> H) {
        forn(i, N+1) forn(j, W) forn(k, 2) memo[i][j][k] = -1;
        cout << dp(N, 0, true) << endl;
    }

    return 0;
}
