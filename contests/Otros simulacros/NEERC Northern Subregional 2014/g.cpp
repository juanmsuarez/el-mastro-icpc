#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

bool can(int w, int h, int W, int H) {
    return w <= W && h <= H;
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}

int main() {
    fastio;

    freopen("grave.in", "r", stdin);
    freopen("grave.out", "w", stdout);
    
    int gx1, gy1, gx2, gy2; cin >> gx1 >> gy1 >> gx2 >> gy2;
    int cx1, cy1, cx2, cy2; cin >> cx1 >> cy1 >> cx2 >> cy2;
    int w, h; cin >> w >> h;

    if (can(w, h, gx2 - cx2, gy2 - gy1)) yes();
    if (can(w, h, gx2 - gx1, gy2 - cy2)) yes();
    if (can(w, h, cx1 - gx1, gy2 - gy1)) yes();
    if (can(w, h, gx2 - gx1, cy1 - gy1)) yes();

    cout << "No" << endl;
    
    return 0;
}
