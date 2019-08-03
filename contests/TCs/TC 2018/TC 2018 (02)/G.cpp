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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

int main() {
    fastio;

    int t, sx, sy, ex, ey, ans = -1;
    cin >> t >> sx >> sy >> ex >> ey;

    if (sx == ex && sy == ey) ans = 0;
    else {
        forn(i, t) {
            char c; cin >> c;
            if (c == 'N' && sy < ey) sy++;
            if (c == 'S' && sy > ey) sy--;
            if (c == 'E' && sx < ex) sx++;
            if (c == 'W' && sx > ex) sx--;
            if (sx == ex && sy == ey) {
                ans = i+1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
