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
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int,int> ti;
typedef long long int ll;

const int MAXN = 30+5, MAXT = 1e4+5, INF = 1e9;
int n, m, memo[MAXN][MAXT][MAXN][MAXN], tiempoSum[MAXN], last;
ti nxt[MAXN][MAXT][MAXN][MAXN];
ii p[MAXN];
bool can[MAXT];

/*
inline int tiempo(int procesando, int tiempoProcesado, int aVender) {
    return ;
}
*/

int dp(int procesando, int tiempoProcesado, int aVender, int vendidos) {
    if (procesando == n && aVender == 0) return 0;
    int t = tiempoSum[procesando] + tiempoProcesado + vendidos;
    if (t >= last) return aVender == 0 ? 0 : -INF; 

    int &res = memo[procesando][tiempoProcesado][aVender][vendidos];
    if (res != -1) return res;
    res = -INF;

    if (procesando < n) {
        if (p[procesando].fi == tiempoProcesado+1) {
            int val = dp(procesando+1, 0, aVender+1, vendidos) + p[procesando].se;
            if (res < val) {
                res = val;
                nxt[procesando][tiempoProcesado][aVender][vendidos] = {procesando+1, 0, aVender+1, vendidos};           
            }
        }
        else {
            int val = dp(procesando, tiempoProcesado+1, aVender, vendidos);
            if (res < val) {
                res = val;
                nxt[procesando][tiempoProcesado][aVender][vendidos] = {procesando, tiempoProcesado+1, aVender, vendidos};           
            }
        }
    }

    if (tiempoProcesado == 0) {
        int val = dp(procesando+1, 0, aVender, vendidos);
        if (res < val) {
            res = val;
            nxt[procesando][tiempoProcesado][aVender][vendidos] = {procesando+1, 0, aVender, vendidos};           
        }
    }

    if (can[t] && aVender > 0) {
        int val = dp(procesando, tiempoProcesado, aVender-1, vendidos+1);
        if (res < val) {
            res = val;
            nxt[procesando][tiempoProcesado][aVender][vendidos] = {procesando, tiempoProcesado, aVender-1, vendidos+1};           
        }
    }

    return res;
}

int main() {
    fastio;

    cin >> n >> m;
    tiempoSum[0] = 0;
    forn(i, n) {
        cin >> p[i].se >> p[i].fi;
        tiempoSum[i+1] = tiempoSum[i] + p[i].fi;
    }
    last = 0;
    forn(i, m) {
        int l, r; cin >> l >> r;
        last = max(last, r);
        forsn(t, l, r) can[t] = true; 
    }

    sort(p, p+n);


    forn(i, n+1) forn(j, last) forn(k, n) forn(l, n) {
        memo[i][j][k][l] = -1;
        nxt[i][j][k][l] = {-1,-1,-1,-1};
    }

    int ans = dp(0, 0, 0, 0);
    vii v;

    ti act = {0,0,0,0};
    while (act != (ti){-1, -1, -1, -1}) {
        int procesando, tiempoProcesado, aVender, vendidos, nxtVendidos;
        tie(procesando, tiempoProcesado, aVender, vendidos) = act;
        nxtVendidos = get<3>(nxt[procesando][tiempoProcesado][aVender][vendidos]);
               
        if (nxtVendidos == vendidos+1)
            v.pb(procesando, tiempoProcesado);
    }

    cout << ans << ' ' << si(v) << endl;
    for (ii x : v) cout << x.fi << ' ' << x.se << endl;

    return 0;
}
