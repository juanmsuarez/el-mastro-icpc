#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int dx[] = {1, 0, -1}, dy[] = {1, 0, -1}, dz[] = {1, 0, -1};
const int MAXW = 100+10, MAXN = 20+5;
string s[MAXN];
int w, n;
char c[MAXN][MAXN][MAXN], ans[MAXW];
map<string, int> m;

bool valid(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 &&
        x < n && y < n && z < n;
}

int main() {
    fastio;

    char _;
    cin >> w >> _ >> n;
    forn(i, w) {
        string s;
        cin >> s;
        m[s] = i;
    }
    forn(z, n)
        forn(y, n) {
            if (y) cin >> _;
            forn(x, n) 
                cin >> c[x][y][z];
        }

    forn(x, n) forn(y, n) forn(z, n)
        forn(i, 3) forn(j, 3) forn(k, 3) {
            if (dx[i] == 0 && dy[j] == 0 && dz[k] == 0) continue;

            int nx = x, ny = y, nz = z, 
                px = x-dx[i], py = y-dy[j], pz = z - dz[k];
            char pre = valid(px, py, pz) ? c[px][py][pz] : 0;
            //cerr << "pre " << pre << ' ' << px << ' ' << py << ' ' << pz << endl;
            string s;

            while (valid(nx, ny, nz)) {
                s += c[nx][ny][nz];

                //cerr << "act " << s << ' ' << nx << ' ' << ny << ' ' << nz << endl;

                nx += dx[i];
                ny += dy[j];
                nz += dz[k];

                if (m.count(s)) {
                    if (pre != 0) 
                        ans[m[s]] = pre;
                    else if (valid(nx, ny, nz)) 
                        ans[m[s]] = c[nx][ny][nz];
                }
            }
        }

    string s;
    forn(i, w)
        if (ans[i] != 0)
            s += ans[i];
    cout << s << endl;

    return 0;
}
