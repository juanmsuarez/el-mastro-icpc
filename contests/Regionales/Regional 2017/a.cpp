#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 15+5, MAXK = 1e4+5, INF = 1e9;
const double DINF = 1e18;

struct point {
    int x, y;
    point(int x=0, int y=0) : x(x), y(y) {}
};

vector<point> points[MAXN][2]; // [0] = left, [1] = right
int n, extremes[MAXN][2];
double dist[MAXN][MAXN], memo[MAXN][1<<MAXN];

double dp(int u, int left) {
    if (left == 0) return 0;

    double &res = memo[u][left];
    if (res != DINF) return res;

    forn(v, n)
        if ((1 << v) & left)
            res = min(res, dp(v, left ^ (1 << v)) + dist[u][v]); 

    return res;
}

int main() {
    fastio;

    cin >> n;
    
    forn(i, n) {
        int k;
        cin >> k;

        point first;
        cin >> first.x >> first.y;

        bool right = true;
        forn(_, k-1) {
            point p;
            cin >> p.x >> p.y;

            if (right && !points[i][1].empty() && p.y == points[i][1].back().y) right = false;

            points[i][right].pb(p);
        }
        points[i][0].pb(first);
        reverse(all(points[i][0]));

        extremes[i][0] = INF, extremes[i][1] = -INF;
        for (point p : points[i][0]) extremes[i][0] = min(extremes[i][0], p.x);
        for (point p : points[i][1]) extremes[i][1] = max(extremes[i][1], p.x);
        /* poligonos
        cerr << "poligono " << i << endl;
        cerr << "left: " << endl;
        for (point p : points[i][0]) cerr << p.x << ' ' << p.y << endl;
        cerr << "right: " << endl;
        for (point p : points[i][1]) cerr << p.x << ' ' << p.y << endl;
        cerr << endl;
        */
    }

    // n = nodo especial
    forn(i, n) dist[n][i] = extremes[i][1] - extremes[i][0];
    forn(i, n)
        forn(j, n) {
            if (i == j) continue;

            int indLeft = 0, indRight = 0; 
            double minDif = INF;
            while (indLeft < si(points[i][1]) && indRight < si(points[j][0])-1) {
                int x = points[i][1][indLeft].x, y = points[i][1][indLeft].y;

                point a = points[j][0][indRight], b = points[j][0][indRight+1];
                if (a.y <= y && y <= b.y) {
                    double intX = a.x + (y - a.y) * double(b.x - a.x) / (b.y - a.y);
                    minDif = min(minDif, extremes[i][1] - x + intX - extremes[j][0]);

                    indLeft++;
                }                
                else indRight++;
            }

            indLeft = 0, indRight = 0;
            while (indLeft < si(points[i][1])-1 && indRight < si(points[j][0])) {
                int x = points[j][0][indRight].x, y = points[j][0][indRight].y;

                point a = points[i][1][indLeft], b = points[i][1][indLeft+1];
                if (a.y <= y && y <= b.y) {
                    double intX = a.x + (y - a.y) * double(b.x - a.x) / (b.y - a.y);
                    minDif = min(minDif, x - extremes[j][0] + extremes[i][1] - intX);

                    indRight++;
                }                
                else indLeft++;
            }

            dist[i][j] = extremes[j][1] - extremes[j][0] - minDif; 
        }

    n++;

    /* distancias
    forn(i, n) {
        forn(j, n) cerr << dist[i][j] << ' ';
        cerr << endl;
    }
    */
    fill(memo[0], memo[MAXN], DINF);

    cout << fixed << setprecision(3) << dp(n-1, ((1<<n)-1) ^ (1<<(n-1))) << endl;

    return 0;
}
