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

const int MAXN = 100+10;
char a[MAXN][MAXN];
bool open[MAXN];

int main() {
    fastio;

    freopen("ascii.in", "r", stdin);
    freopen("ascii.out", "w", stdout);

    int h, w; cin >> h >> w;
    forn(i, h) forn(j, w) cin >> a[i][j];

    int half = 0, full = 0;
    forn(j, w) {
        forn(i, h) {
            if (a[i][j] == '.') full += open[i];
            if (a[i][j] == '/' || a[i][j] == '\\') {
                half++;
                open[i] ^= true;
            }
        }
    }

    cout << half/2 + full << endl;

    return 0;
}
