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

const int MAXN = 100+10;
int r, c;
int v[MAXN][MAXN], w[MAXN][MAXN], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[MAXN][MAXN];

void go(int x, int y) {
    vis[x][y] = true;

    forn(d, 4) {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < r && ny < c 
                && !vis[nx][ny] && v[x][y] == v[nx][ny])
            go(nx, ny);
    }
}

inline int sign(int x) {
    return (x > 0) - (x < 0);
}

void solve(int &faces) {
    faces++;
    forn(x, r-1) {
        int prevStart = 0, prevEnd = 0, prevS = 0;
        forn(y, c) {
            int start = v[x][y], end = v[x+1][y], s = sign(end - start);
            if (start > end) swap(start, end);

            if (start != end) {
                if (prevS != s || start >= prevEnd || end <= prevStart) 
                    faces++;
            }
            
            prevStart = start; prevEnd = end; prevS = s;
        }
    }
    faces++;
}

int main() {
    fastio;

    while (cin >> r >> c) {
        fill(vis[0], vis[MAXN], false);
        forn(i, r) forn(j, c) cin >> v[i][j];

        int faces = 1;

        forn(x, r) forn(y, c)
            if (!vis[x][y]) {
                go(x, y);
                faces++;
            }

        solve(faces);
        forn(x, r) forn(y, c) w[y][x] = v[x][y];
        swap(r, c);
        forn(x, r) forn(y, c) v[x][y] = w[x][y];
        solve(faces);

        cout << faces << endl;
    }

    return 0;
}
