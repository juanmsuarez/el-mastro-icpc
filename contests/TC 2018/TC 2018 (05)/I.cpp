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
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int INF = 2e9+10;

int n, m, d, len; 
vi holes;
set<int,greater<int>> ls; set<int> rs;

// how many outside every dj but reachable by m 
int countOut(int mid) {
    auto itl = ls.lower_bound(mid); auto itr = rs.lower_bound(mid);
    int l = itl == ls.end() ? -INF : *itl+len+1,
        r = itr == rs.end() ? INF : *itr-len-1;

    if (r < l) return 0;
    l = max(l, mid-len); r = min(r, mid+len);

    int holeL = lower_bound(all(holes), l) - holes.begin(),
        holeR = upper_bound(all(holes), r) - holes.begin();
    return holeR - holeL;
};


int main() {
    fastio;

    cin >> n >> m >> d >> len;
    // holes
    holes = vi(n); holes[0] = 0; forsn(i, 1, n) cin >> holes[i];
    // djs
    int ans = 0;
    forn(_, m) {
        int mid; cin >> mid;
        ans += countOut(mid);
        ls.insert(mid);
        rs.insert(mid);
    }

    // queries
    forn(_, d) {
        int s, e;
        cin >> s >> e;

        cout << ans << endl;

        ls.erase(s); rs.erase(s);
        
        ans -= countOut(s); 
        ans += countOut(e);

        ls.insert(e); rs.insert(e);
    }
    cout << ans << endl;

    return 0;
}
