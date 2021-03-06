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

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vi ans;

    int lo = 1, hi = n;
    bool m = true;
    forn(_, n-k) ans.pb(lo++);
    forn(_, k) {
        if (m) {
            ans.pb(hi);
            hi--;
        }
        else {
            ans.pb(lo);
            lo++;
        }
        m ^= true; 
    }

    forn(i, si(ans)) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
