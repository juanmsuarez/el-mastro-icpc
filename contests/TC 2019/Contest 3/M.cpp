#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define snd second
using ll = long long;
using pii = pair<int, int>;

ll f(int c) {
    return (ll)c*(c-1)/2;
}

int main() {
    int n; cin >> n;
    map<int, int> cx, cy;
    map<pii, int> cxy;
    forn(i, n) {
        int x, y; cin >> x >> y;
        cx[x]++, cy[y]++, cxy[{x,y}]++;
    }

    ll ans = 0;
    for (auto p : cx) ans += f(p.snd);
    for (auto p : cy) ans += f(p.snd);
    for (auto p : cxy) ans -= f(p.snd);

    cout << ans << endl;
    //upsolving
}
