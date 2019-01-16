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

const int MAXN = 1e6+10;
int cnt[MAXN];

int main() {
    fastio;

    freopen("deposits.in","r",stdin);
    freopen("deposits.out","w",stdout);

    int n;
    cin >> n;
    forn(_, n) {
        int a;
        cin >> a;

        for (int i = 1; i*i <= a; i++) {
            if (a % i == 0) {
                cnt[i]++;

                if (i*i != a)
                    cnt[a/i]++;
            }
        }
    }

    ll ans = 0; 
    int m;
    cin >> m;

    forn(i, m) {
        int b;
        cin >> b;
        ans += cnt[b];
    }
    cout << ans << endl;

    return 0;
}
