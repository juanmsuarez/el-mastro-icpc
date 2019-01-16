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

const int MAXN = 300+5, INF = 1e9;
int n, x[MAXN], y[MAXN], pre[MAXN][MAXN];
int p[MAXN][MAXN];
vi sx, sy;
map<int,int> invx, invy;

inline int sum(int a, int b, int c, int d) {
    return pre[c+1][d+1] - pre[a][d+1] - pre[c+1][b] + pre[a][b];
}
inline bool can(int a, int b, int c, int d) {
    return sum(a,b,c,d) >= (n+1)/2;
}

int main() {
    fastio;

    int nc;
    cin >> nc;

    while (nc--) {
        //clear
        invx.clear(); invy.clear();
        sx.clear(); sy.clear();
        fill(p[0], p[MAXN], 0);

        // read input
        cin >> n;
        forn(i, n) {
            cin >> x[i] >> y[i];
            sx.pb(x[i]); sy.pb(y[i]);
        }

        // compress
        sort(all(sx)); sort(all(sy));
        sx.erase(unique(all(sx)), sx.end()); sy.erase(unique(all(sy)), sy.end());
        forn(i, si(sx))
            invx[sx[i]] = i;
        forn(i, si(sy))
            invy[sy[i]] = i;

        // points
        forn(i, n) p[invx[x[i]]][invy[y[i]]]++;

        // prefix sum
        forn(i, si(sx)) forn(j, si(sy)) {
            pre[i+1][j+1] = p[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i][j];
        }

        //forn(i, si(sx)+1) forn(j, si(sy)+1) cerr << i << ' ' << j << ' ' << pre[i][j] << endl;

        int mn = INF;
        forn(x1, si(sx))
            forsn(x2, x1, si(sx)) 
                forn(y1, si(sy)) {
                    if (!can(x1, y1, x2, si(sy)-1)) continue;
                    //cerr << "ok" << endl;
                    if (can(x1, y1, x2, y1)) {
                        mn = min(mn, 0);
                        continue;
                    }

                    int lo = y1, hi = si(sy)-1;
                    while (hi - lo > 1) {
                        int mid = (lo + hi) / 2;

                        if (can(x1, y1, x2, mid))
                            hi = mid;
                        else
                            lo = mid;
                    }

                    int y2 = hi;
                    //cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << " suma " << sum(x1, y1, x2, y2) << ' ' << " area " <<(sx[x2]-sx[x1])*(sy[y2]-sy[y1]) <<  endl;
                    if (can(x1, y1, x2, y2))
                        mn = min(mn, (sx[x2]-sx[x1])*(sy[y2]-sy[y1]));
                } 
        cout << mn << endl;
    }

    return 0;
}
