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
    #define DBG(a) //cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 500+10;
int h, w, a[MAXN][MAXN];
bool used[MAXN][MAXN];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1},
    dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

inline bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
}

int main() {
    fastio;

    cin >> h >> w;
    forn(i, h) forn(j, w) {
        cin >> a[i][j];
        if (a[i][j] > 0) a[i][j] = 0;
        else a[i][j] = -a[i][j];
    }
    int x, y;
    cin >> x >> y;
    x--, y--;

    priority_queue<tuple<int,int,int>> pq;
    int H = a[x][y];
    pq.push(make_tuple(H, x, y));
    used[x][y] = true;

    tint ans = 0;
    while (!pq.empty()) {
        int h, x, y;
        tie(h, x, y) = pq.top();
        pq.pop();

        ans += a[x][y];
        //cerr << x << ' ' << y << endl;

        forn(i, 8) {
            int nx = x + dx[i], ny = y + dy[i];

            if (valid(nx, ny) && !used[nx][ny] && a[nx][ny] > 0) {
                //cerr << 'a' << nx << ' ' << ny << endl;
                int nh = min(a[nx][ny], h);
                a[nx][ny] = nh;
                used[nx][ny] = true;
                pq.push(make_tuple(nh, nx, ny));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
