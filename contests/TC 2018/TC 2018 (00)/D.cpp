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

const int MAXN = 1e6+10, INF = 1e9;
int a[MAXN], s[MAXN];

int main() {
    fastio;

    int l, n;
    cin >> l >> n;

    forn(i, n) {
        cin >> a[i]; 
        s[i+1] = s[i] + a[i];
    }
    a[n] = -INF;

    ll ans = 0;
    vi pos;
    forn(i, n) {
        int k = (s[i+1] + l - 1) / l;
        ans += k;

        int resto = s[i+1]%l;
        if (resto == 0 && s[i+1] > 0) resto = l;

        if (resto > 0 && resto <= a[i] && l-a[i+1] >= resto && (s[i+1] - resto + l - 1) / l < k)
            pos.pb(i);
    }
    
    cout << ans << endl;
    forn(i, si(pos)) {
        if (i) cout << ' ';
        cout << pos[i]+1;
    }
    cout << endl;

    return 0;
}
