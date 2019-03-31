#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
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
typedef long long int tint;

const int MAXN = 15+1;
const tint INF = 1e12*15;
int n, k;
tint w[MAXN], h[MAXN], q[MAXN];
tint memo[1<<MAXN][MAXN], cost[1<<MAXN];

inline tint calcCost(int mask) {
    tint mxH = 0, mxW = 0;
    tint ans = 0, cant = 0;
    forn(i, n)
        if ((1<<i) & mask) {
            mxW = max(mxW, w[i]);
            mxH = max(mxH, h[i]);
            cant += q[i]; 

            ans -= w[i]*h[i]*q[i];
        }

    ans += mxH*mxW*cant;

    return ans;
}

tint dp(int mask, int k) {
    if (mask == 0) return 0;
    if (k == 1) return cost[mask];

    tint &ans = memo[mask][k];
    if (ans != INF) return ans;

    for (int nxt = mask; nxt > 0; nxt = ((nxt-1)&mask)) 
        ans = min(ans, cost[nxt] + dp((mask ^ nxt), k-1));

    return ans;
}

int main() {
    fastio;

    cin >> n >> k;

    forn(i, n) cin >> w[i] >> h[i] >> q[i];

    forn(mask, (1<<n))
        cost[mask] = calcCost(mask);

    fill(memo[0], memo[1<<MAXN], INF);
    cout << dp((1<<n)-1, k) << endl;

    return 0;
}
