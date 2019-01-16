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

const int MAXN = 1e5+10, INF = 1<<30;
int xs[MAXN], ys[MAXN], acumXs[MAXN], acumYs[MAXN];
set<int> xs1, ys1;
set<int, greater<int>> xs1Inv, ys1Inv;
int ax, ay, bx, by;

inline int sumX(int x1, int x2) {
    return acumXs[x2] - acumXs[x1];
}
inline int sumY(int y1, int y2) {
    return acumYs[y2] - acumYs[y1];
}

int getPathX(int x) { // ay < by
    int yLow = ay + abs(ax-x) - (ax>x), yHigh = by - abs(bx-x) + (bx>x); 
    
    if (yLow > yHigh) return INF;

    int dif = yHigh - yLow, 
        extras = dif - (dif%2==(x < min(ax,bx) || x >= max(ax,bx))) - !(x < min(ax,bx) || x >= max(ax,bx)),
        outOfPath = (x > max(ax, bx) ? sumX(max(ax,bx),x) : 0)  + (x < min(ax,bx) ? sumX(x+1, min(ax,bx)) : 0);

    return extras * xs[x] + 2*outOfPath;
}

int getPathY(int y) { // ax < bx
    int xLow = ax + abs(ay-y) - (ay>y), xHigh = bx - abs(by-y) + (by>y);
   
    if (xLow > xHigh) return INF; 
    
    int dif = xHigh - xLow, 
        extras = dif - (dif%2==(y < min(ay,by) || y >= max(ay,by))) - !(y < min(ay,by) || y >= max(ay,by)),
        outOfPath = (y > max(ay, by) ? sumY(max(ay,by),y) : 0)  + (y < min(ay,by) ? sumY(y+1, min(ay,by)) : 0);

    return extras * ys[y] + 2*outOfPath;
}

int main() {
    fastio;

    int n;
    cin >> n;
    
    forn(i, n-1) {
        cin >> xs[i];
        if (xs[i] == 1) xs1.insert(i), xs1Inv.insert(i);
        acumXs[i+1] = acumXs[i] + xs[i];
    }

    forn(i, n-1) {
        cin >> ys[i];
        if (ys[i] == 1) ys1.insert(i), ys1Inv.insert(i);
        acumYs[i+1] = acumYs[i] + ys[i];
    }

    int q;
    cin >> q;

    while (q--) {
        cin >> ax >> ay >> bx >> by;
        ax--; ay--; bx--; by--;
        int dx = abs(ax-bx), dy = abs(ay-by);

        int base = sumX(min(ax,bx), max(ax,bx)) + sumY(min(ay,by), max(ay,by)), best;
        if (dx < dy) {
            if (ay > by) swap(ax,bx), swap(ay,by); // asi ay < by
            auto xPrevIt = xs1Inv.upper_bound(max(ax,bx)), xNextIt = xs1.lower_bound(min(ax,bx));

            best = getPathX(min(n-2, min(ax,bx)));
            if (xPrevIt != xs1Inv.end()) best = min(best, getPathX(*xPrevIt));
            if (xNextIt != xs1.end()) best = min(best, getPathX(*xNextIt));
        }
        else {
            if (ax > bx) swap(ax,bx), swap(ay,by); // asi ax < bx
            auto yPrevIt = ys1Inv.upper_bound(max(ay,by)), yNextIt = ys1.lower_bound(min(ay,by));

            best = getPathY(min(n-2, min(ay,by)));
            if (yPrevIt != ys1Inv.end()) best = min(best, getPathY(*yPrevIt));
            if (yNextIt != ys1.end()) best = min(best, getPathY(*yNextIt));
        }

        cout << base + best << endl;
    }

    return 0;
}
