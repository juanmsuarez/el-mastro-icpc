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
vi divs[MAXN];
int dp[MAXN];
bool present[MAXN];

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) {
        int a;
        cin >> a;
        present[a] = true;
    }

    int ans = 0;
    forsn(i, 1, MAXN) { 
        if (present[i]) {
            dp[i] = max(dp[i], 1);

            //cerr << i << ' ' << dp[i] << endl;

            for (int j = 2*i; j < MAXN; j += i) {
                if (present[j]) {
                    dp[j] = max(dp[j], dp[i]+1);
                    //cerr << "act " << j << ' ' << dp[j] << endl;
                }
            }

            ans = max(ans, dp[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
