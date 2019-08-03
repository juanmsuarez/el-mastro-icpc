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

const int N = 10, M = 1<<N, INF = 1e9;
int d, h, w, memo[N][N][M];
char c[N][N][N];

vi separate(int i, int j, int mask) {
    int bmask = 0, wmask = 0;
    forn(k, d) 
        if (c[k][i][j] == 'B') bmask += 1<<k; 
        else wmask += 1<<k;
    bmask &= mask; wmask &= mask;

    vi v;
    if (wmask != 0) v.pb(wmask);
    if (bmask != 0) v.pb(bmask);

    return v;
}

int dp(int i, int j, int mask);

int getCost(int i, int j, int ni, int nj, vi &nmasks) {
    int cost = 0;
    for (int nmask : nmasks) cost = max(cost, dp(ni, nj, nmask));
    return cost + abs(ni - i) + abs(nj - j);
}

int dp(int i, int j, int mask) {
    if ((mask & (mask-1)) == 0) return 0;

    int &res = memo[i][j][mask];
    if (res != INF) return res;

    forn(ni, h) forn(nj, w) {
        vi nmasks = separate(ni, nj, mask);
        if (si(nmasks) != 2) continue;
        
        res = min(res, getCost(i, j, ni, nj, nmasks));
    }

    return res;
}

void print(int i, int j, int mask) {
    if ((mask & (mask-1)) == 0) { cout << 31 - __builtin_clz(mask); return; }

    cerr << i << ' ' << j << ' ' << mask << endl;
    
    int best = INF, bni, bnj;
    forn(ni, h) forn(nj, w) {
        vi nmasks = separate(ni, nj, mask);
        if (si(nmasks) != 2) continue;

        int res = getCost(i, j, ni, nj, nmasks);
        if (res < best) best = res, bni = ni, bnj = nj;
    }

    while (i < bni) cout << 'D', i++;
    while (i > bni) cout << 'U', i--;
    while (j < bnj) cout << 'R', j++;
    while (j > bnj) cout << 'L', j--;

    vi sep = separate(i, j, mask);
    cout << '('; 
    print(i, j, sep[0]);
    cout << ':';
    print(i, j, sep[1]);
    cout << ')';
}

int main() {
	fastio;

    freopen("image.in", "r", stdin);
    freopen("image.out", "w", stdout);

    fill(memo[0][0], memo[N][0], INF);
	
    cin >> d >> h >> w;        
    forn(k, d) forn(i, h) forn(j, w) cin >> c[k][i][j];

    print(0, 0, (1<<d)-1); 
    cout << endl;
	
	return 0;
}
