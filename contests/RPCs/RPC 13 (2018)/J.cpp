#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 3e5+10, M = 5e3+10, INF = 1e9,
      dx[] = {1, 1, 1, 0, -1, -1, -1, 0},
      dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
pii guards[N];
int n, dist[M][M];

inline bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < M && y < M;
}

void bfs() {
    queue<pii> q;
    forn(i, n) {
        q.push(guards[i]);
        int x, y; tie(x, y) = guards[i];
        dist[x][y] = 0;
    }

    while (!q.empty()) {
        int x, y; tie(x, y) = q.front(); q.pop();

        forn(d, 8) {
            int nx = x + dx[d], ny = y + dy[d];
            if (valid(nx, ny) && dist[nx][ny] == INF) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
	fastio;
	
    fill(dist[0], dist[M], INF);

    int q; cin >> n >> q;
    forn(i, n) cin >> guards[i].fst >> guards[i].snd;

    bfs();

    while (q--) {
        int x, y; cin >> x >> y;
        cout << dist[x][y] << endl;
    }
	
	return 0;
}
