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

const int MAXN = 2e5+10, MAXQ = 2e5+10, MAXK = 100+10;

int a[MAXN], x[MAXN], y[MAXN];
vi ord[MAXQ];

struct rmq {
    int sz, t[1<<19][MAXK];

    void init(int n) {
        sz = 1<<(32 - __builtin_clz(n)); 

        forn(i, 2*sz) forn(j, MAXK) t[i][j] = j;
    }

    int* operator [] (int i) { return t[i]; }

    void upd(int k) { upd(k, 1, 0, sz); }
    void upd(int k, int n, int a, int b) {
        if (a+1 == b) {
            forn(i, MAXK) t[n][i] = k > 0 && x[k-1] == t[n][i] ? y[k-1] : i;
            return;
        }

        int c = (a+b)/2;
        if (abs(k)-1 < c) upd(k, 2*n, a, c); 
        else upd(k, 2*n+1, c, b);
        forn(i, MAXK) t[n][i] = t[2*n+1][t[2*n][i]];
    }
} rmq;

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) cin >> a[i];

    int m;
    cin >> m;

    forn(k, m) {
        int l, r;
        cin >> l >> r >> x[k] >> y[k];
        l--;

        ord[l].pb(k+1);
        ord[r].pb(-(k+1));
    }

    rmq.init(m);
    forn(i, n) {
        for (int k : ord[i]) rmq.upd(k);

        if (i) cout << ' ';
        cout << rmq[1][a[i]];
    } 
    cout << endl;

    return 0;
}
