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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXD = 15, MAXR = 110;
int x;

ll n, pot10[MAXD], pot10x[MAXD], memo[MAXD][2][MAXR][MAXR];

ll dp(int pos, bool eq, int r, int s) {
    if (pos == -1) return r == 0 && s == x;

    ll &ans = memo[pos][eq][r][s];
    if (ans != -1) return ans;
    ans = 0;

    if (eq) {
        int dig = (n/pot10[pos])%10;
        forn(d, dig)
            ans += dp(pos-1, false, (r+(d*pot10x[pos]%x))%x, s+d);

        ans += dp(pos-1, true, (r+(dig*pot10x[pos])%x)%x, s+dig);
    }
    else {
        forn(d, 10)
            ans += dp(pos-1, false, (r+(d*pot10x[pos]%x))%x, s+d);
    }

    return ans;
}

int main() {
    fastio;

    freopen("just.in", "r", stdin);
    freopen("just.out", "w", stdout);

    cin >> n;

    pot10[0] = 1;
    forsn(d, 1, MAXD) pot10[d] = pot10[d-1]*10;

    ll ans = 0;
    for(x = 1; x < MAXR; x++) {
        forn(d, MAXD) pot10x[d] = pot10[d]%x;
        fill(memo[0][0][0], memo[MAXD][0][0], -1);
        ans += dp(12, true, 0, 0);
    }

    cout << ans << endl;

    return 0;
}
