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

const int MAXN = 3e6+10;
int p[MAXN], sz[MAXN], cant[MAXN];

int main() {
    fastio;

    int n;
    cin >> n;
    forsn(u, 1, n) {
        cin >> p[u];
        p[u]--;
    }

    forn(u, n) sz[u] = 1;
    dforsn(u, 1, n) sz[p[u]] += sz[u];
    forn(u, n) cant[sz[u]]++;

    forsn(k, 1, n+1) {
        for (int j = 2*k; j <= n; j += k) cant[k] += cant[j];
        //cerr << "sz " << k << " cant " << cant[k] << endl;
    }

    vi ans;
    forsn(i, 1, n+1) if (n%i == 0 && cant[n/i] == i) ans.pb(i);

    forn(i, si(ans)) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
