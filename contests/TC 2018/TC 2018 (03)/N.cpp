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

const int MAXN = 400+10;
bool a[MAXN][MAXN];

int main() {
    fastio;

    int nc;
    cin >> nc;
    forn(_, nc) {
        int m, n;
        cin >> m >> n;
        forn(i, m) forn(j, n) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }

        int c = 0;
        forn(i, m)
            dforsn(j, 0, n)
                if (!a[i][j]) {
                    forn(k, j+1) a[i][k] ^= true;
                    forsn(k, i, m) a[k][j] ^= true;
                    c++;
                }

        cout << c << endl;
    }

    return 0;
}
