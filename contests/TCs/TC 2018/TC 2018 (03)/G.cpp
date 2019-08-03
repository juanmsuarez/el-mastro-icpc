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

const int MAXN = 1e6+10;
string s[MAXN], t[MAXN];
set<string> c;

void go(string x) {
    if (c.count(x)) c.erase(x);
    else c.insert(x);
}

int main() {
    fastio;

    int nc;
    cin >> nc;

    while (nc--) {
        int n;
        cin >> n;
        forn(i, n) cin >> s[i];
        forn(i, n) cin >> t[i];

        vi ans;
        int p = -1;
        forn(i, n) {
            go(s[i]);
            go(t[i]);

            if (c.empty()) {
                ans.pb(i-p);
                p = i;
            }
        }

        forn(i, si(ans)) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
