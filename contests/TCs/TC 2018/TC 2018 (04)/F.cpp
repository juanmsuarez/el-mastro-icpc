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

const int MAXN = 500+10, INF = 1e9;
ll a[MAXN][MAXN], x[MAXN], dist[MAXN][MAXN], ans[MAXN];

int main() {
    fastio;

    int n;
    cin >> n;
    forn(u, n) forn(v, n) cin >> dist[u][v];
    forn(i, n) {
        cin >> x[i];
        x[i]--;
    }

    ll suma = 0;
    dforsn(k, 0, n) {
        int w = x[k];
        //cerr << "paso " << endl;

        forn(i, n)
            forn(j, n) {
                if (i == j) continue;
                int u = x[i], v = x[j];

                if ((i == k || j == k) && (i > k || j > k))
                    suma += dist[u][w] + dist[w][v];

                if (dist[u][w] + dist[w][v] < dist[u][v]) {
                    if (i > k && j > k)
                        suma -= dist[u][v] - (dist[u][w] + dist[w][v]);
                    dist[u][v] = dist[u][w] + dist[w][v];
                }
            }

        /*
        forn(u, n) {
            forn(v, n) cerr << setw(10) << dist[u][v] << ' ';
            cerr << endl;
        }
        cerr << endl;
        */

        ans[k] = suma;
    }

    forn(i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
