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

const double EPS = 1e-7;
const int MAXN = 1e3+10;
double dp[MAXN];
int ans[MAXN];

int main() {
    fastio;

    int k, q;
    cin >> k >> q;

    int d = 0;
    dp[0] = 1;
    forsn(p, 1, MAXN) {
        while (d < k || dp[k]*2000 < p - EPS) {
            dforsn(i, 0, k+1) {
                dp[i] = dp[i]*i/k;        
                if (i > 0) dp[i] += dp[i-1]*(k-(i-1))/k;
            }
            d++;
        }

        ans[p] = d;
    }

    forn(_, q) {
        int p;
        cin >> p;
        cout << ans[p] << endl;
    }

    return 0;
}
