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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 1e3+10, K = 4, INF = 2e9;
int n, m; 

struct Point {
    int x, y;
    Point operator + (const Point &o) const { return {x + o.x, y + o.y}; }
    bool operator < (const Point &o) const { return mp(x, y) < mp(o.x, o.y); }
    bool operator == (const Point &o) const { return x == o.x && y == o.y; }
    bool operator != (const Point &o) const { return x != o.x || y != o.y; }
    bool valid() { return x >= 0 && y >= 0 && x < n && y < m; }
};
struct Street { 
    Point s, f;
};
enum Direction {UP, RIGHT, DOWN, LEFT};

vector<Street> streets;
int cost[N][N][K];
Point start, finish;
Point moves[K] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void compress() {
    vi xs, ys;

    auto addPoint = [&xs, &ys](const Point &p) { xs.pb(p.x), ys.pb(p.y); };
    for (Street st : streets) addPoint(st.s), addPoint(st.f);
    addPoint(start), addPoint(finish);
    addPoint({-INF, -INF}), addPoint({INF, INF});

    sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
    sort(all(ys)); ys.erase(unique(all(ys)), ys.end());

    auto mapPoint = [&xs, &ys](Point &p) { 
        auto getCoord = [](vi &v, int x) { return lower_bound(all(v), x) - v.begin(); };
        p = {getCoord(xs, p.x), getCoord(ys, p.y)}; 
    };

    for (Street &st : streets) mapPoint(st.s), mapPoint(st.f);
    mapPoint(start), mapPoint(finish);

    n = si(xs), m = si(ys);
}

void build_graph() {
    forn(x, n) forn(y, m) forn(d, 4) cost[x][y][d] = 0;

    for (Street st : streets) {
        if (st.f < st.s) swap(st.s, st.f);

        while (st.s != st.f) {
            if (st.s.x == st.f.x) {
                cost[st.s.x][st.s.y][LEFT] = 1;

                Point p = st.s + moves[LEFT];
                cost[p.x][p.y][RIGHT] = 1;

                st.s = st.s + moves[UP];
            }
            else {
                cost[st.s.x][st.s.y][DOWN] = 1;

                Point p = st.s + moves[DOWN];
                cost[p.x][p.y][UP] = 1;

                st.s = st.s + moves[RIGHT];
            }
        }
    } 
}

int bfs() {
    deque<Point> deq;
    vector<vi> dist(n, vi(m, INF));

    deq.push_front(start);
    dist[start.x][start.y] = 0;

    while (!deq.empty()) {
        Point p = deq.front(); deq.pop_front();

        if (p == finish) return dist[p.x][p.y];

        forn(dir, 4) {
            Point q = p + moves[dir];
            if (q.valid() && dist[q.x][q.y] == INF) {
                int c = cost[p.x][p.y][dir];
                dist[q.x][q.y] = dist[p.x][p.y] + c;

                if (c == 1) deq.push_back(q);
                else deq.push_front(q);
            }
        }
    }

    return INF;
}

void solve(int s) {
    streets.resize(s); 
    for (Street &st : streets) cin >> st.s.x >> st.s.y >> st.f.x >> st.f.y;
    cin >> start.x >> start.y >> finish.x >> finish.y; 

    compress();
    build_graph();
    int ans = bfs();

    cout << "Peter has to cross " << ans << " streets" << endl;
}

int main() {
	fastio;

    int s, testn = 1;
    while (cin >> s && s != 0) {
        cout << "City " << testn << endl;
        solve(s);    
        testn++;
    }
	
	return 0;
}
