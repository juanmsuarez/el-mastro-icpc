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

const int MAXN = 1e3+10;
int cnt[MAXN];

int main() {
    fastio;

    int nc;
    cin >> nc;
    forn(_, nc) {
        fill(cnt, cnt+MAXN, 0);

        int v;
        cin >> v;
        forn(i, v) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        int best = 0, ans = -1;
        forsn(i, 1, MAXN)
            if (cnt[i] > best) {
                best = cnt[i];
                ans = i;
            }

        cout << ans << endl;
    }

    return 0;
}
