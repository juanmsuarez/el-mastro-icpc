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

const int INF = 1e9;

int main() {
    fastio;

    int n;
    cin >> n;
    map<int,int> f, b;
    vi values;

    forn(i, n) {
        int x, y;
        cin >> x >> y;
        values.pb(x); values.pb(y);
        f[x]++;
        if (y != x) b[y]++;
    }

    sort(all(values));
    values.erase(unique(all(values)), values.end());

    int mn = INF;
    for (int v : values) {
        //cerr << f[v]+b[v] << ' ' << (n+1)/2 << endl;
        if (f[v] + b[v] >= (n+1)/2)  {
            int out = max((n+1)/2 - f[v], 0);
            //cerr << out << endl;
            mn = min(mn, out);
        }
    }

    cout << (mn == INF ? -1 : mn) << endl;

    return 0;
}
