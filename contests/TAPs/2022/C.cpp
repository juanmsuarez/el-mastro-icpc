#include <bits/stdc++.h>

using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int MAX_N = 1e3 + 10;

stuct Point {
    int x, y;
    Point(int _x=0, int _y=0):x(_x), y(_y) {}
};

struct Line {
    int a, b;
    Line (const Point p,const Point q) {
        if (p.x == q.x) {
            a = p.y;
            b = q.y;
        }
        else {
            a = q.x;
            b = p.x;
        }
        if (a > b) swap(a,b);
    }

    bool contains(const Line &o) const {
        return a <= o.a && o.b <= b;
    }

    bool operator <(const Line &o) const {
        if (a == o.a) return b > o.b;
        return a < o.a;
    }
};
vector<Line> Rows[MAX_N], Cols[MAX_N];

void prune(vector<Line> &slice) {
    if (si(slice) == 0) return;
    sort(all(slice));
    int cant = si(slice);
    while (i < cant - 1) {
        int j = i + 1;
        while (j < cant && slice[i].contains(slice[j])) {
            cant--;
            slice[j].a = -1;
            j++;
        }
        i = j;
    }
    int j = 0;
    forn (i, cant) {
        while (slice[j].a == -1) {
            j++;
        }
        if (i != j) swap(slice[i], slice[j]);
        j++;
    }
    slice.resize(cant);
}

bool vis[MAX_N][MAX_N];

int dx[] = {-1, +0, +1, +0},
    dy[] = {+0, +1, +0, -1};

bool inGrid(const Point &p) {
    return 0 <= p.x && p.x < MAX_N - 5 && 0 <= p.y && p.y < MAX_N;
}

bool canCross(int c, vector<Line> &&slice) {
    Line l(c, c);
    int pos = upper_bound(all(slice), l) - slice.begin();
    return pos == 0 || slice[pos-1].b <= c;
}

int dfs(Point u) {
    vis[u.x][u.y] = true;
    
    vector<Line> &cuts[] = {Rows[u.x], Cols[u.y+1], Rows[u.x+1], Cols[u.y]};
    int coord[] = {u.x, u.y+1, u.x+1, u.y};
    int res = 0;
    forn (k, 4) {
        Point v(u.x + dx[k], u.y + dy[k]);
        if (inGrid(v) && !vis[v] && canCross(coord[k], cuts[k])) {
            res += dfs(v);
        }
    }
    return res;
}

int main() {
    fastio;

    forn(i, MAX_N) forn(j, MAX_N) vis[i][j] = false;

    int n;
    cin >> n;

    Point prev;
    cin >> prev.x >> prev.y;
    forn (i, n) {
        Point p;
        cin >> p.x >> p.y;

        Line l(prev, p);
        if (prev.x == p.x) {
            Rows[p.x].pb(l);
        }
        else {
            Cols[p.y].pb(l);
        }
    }

    forn (i, MAX_N) {
        prune(Rows[i]);
        prune(Cols[i]);
    }

    dfs(Point(0, 0);
    res = 0;
    forn (i, MAX_N - 5) {
        forn (j, MAX_N - 5) {
            if (!vis[i][j]) {
                res = max(res, dfs(Point(i, j));
            }
        }
    }

    return 0;
}

