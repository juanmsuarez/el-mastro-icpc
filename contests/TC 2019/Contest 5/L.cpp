
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define forsn(i,s,n) for(int i = (int)s; i < (int) n; i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) ((int)(a).size())
using vi = vector<int>;

const int INF = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    vi a(n); for (int &x : a) cin >> x;

    int mn = INF;
    for (int x : a) mn = min(mn, x);

    int ans = INF, last = -INF;
    forn(i, n) if (a[i] == mn) {
        ans = min(ans, i - last);
        last = i;
    }

    cout << ans << endl;

    return 0;
}
