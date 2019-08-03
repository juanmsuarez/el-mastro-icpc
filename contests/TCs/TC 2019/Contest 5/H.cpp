
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << endl
#else 
    #define D(a)
    #define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define dforsn(i,s,n) for(int i = int(n-1); i >= int(s); i--)
#define forsn(i,s,n) for(int i = (int)s; i < (int)n; i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl "\n"
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int n, a, b, t; 

int solve(vi &cost) {
    vi suf(n+1);
    forn(i, n) suf[i+1] = suf[i] + cost[n-i-1];

    int ans = 0, trem = t;
    forn(i, n) {
        trem -= cost[i] + 1;
        if (trem < 0) break; 

        auto calc = [&](int t, int i) {
            t -= a * (i+1);
            if (t < 0) return 0;
            if (i == n-1) return 0;

            auto can = [&](int pos, int t) {
                return a*pos + suf[pos+1] + pos+1 <= t;
            };

            int lo = 0, hi = n-i-1;
            if (!can(lo, t)) return 0;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (can(mid, t)) lo = mid;
                else hi = mid;
            }

            return lo+1;
        };
        
        ans = max(ans, i+1 + calc(trem, i));

        trem -= a;
    }

    return ans;
}

int main(){
    fastio;
    cin >> n >> a >> b >> t;
    vi cost(n); 
    forn(i, n) { 
        char c; cin >> c;
        cost[i] = (c == 'w') * b;
    }

    int ans = solve(cost);
    cost.pb(cost.front());
    cost.erase(cost.begin());
    reverse(all(cost));
    ans = max(ans, solve(cost));

    cout << ans << endl;

    return 0;
}
