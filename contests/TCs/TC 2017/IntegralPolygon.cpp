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
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int add(int x, int y) {
    return (x+y)%2;
}
int sub(int x, int y) {
    return (x-y+2)%2;
}
int mult(int x, int y) {
    return x*y%2;
}

struct pto {
    int x, y;

    pto(int x = 0, int y = 0) : x(x), y(y) {}

    pto operator - (const pto &o) const {
        return {sub(x, o.x), sub(y, o.y)};
    }

    int operator ^ (const pto &o) const {
        return sub(mult(x, o.y), mult(o.x, y));
    }
};

const int MAXN = 2e5+10;
pto p[2*MAXN];
int area[2*MAXN][2][2], cnt[2*MAXN][2][2];

inline int calcArea(int i, pto o) {
    return (p[i] - o) ^ (p[i+1] - o);
}

int main() {
    fastio;

    int n;
    cin >> n;

    forn(i, n) {
        cin >> p[i].x >> p[i].y;
        p[i].x = (p[i].x%2+2)%2;
        p[i].y = (p[i].y%2+2)%2;

        p[n+i] = p[i];
    }
    p[2*n] = p[n];

    forn(ox, 2) forn(oy, 2) {
        pto o(ox, oy);

        forn(i, 2*n) {
            area[i+1][ox][oy] = add(area[i][ox][oy], calcArea(i, o));
            cnt[i+1][ox][oy] = cnt[i][ox][oy] + (area[i+1][ox][oy] == 0);
        }
    }

    if (area[n][p[0].x][p[0].y] == 0) {
        tint ans = 0;
        forn(i, n) {
            int ox = p[i].x, oy = p[i].y;

            int a = cnt[i+n][ox][oy] - cnt[i][ox][oy];
            if (area[i][ox][oy] == 1) 
                ans += max(0, n - 3 - a);
            else 
                ans += max(0, a-3);
        }
        cout << ans/2 << endl;
    }
    else cout << 0 << endl;

    return 0;
}
