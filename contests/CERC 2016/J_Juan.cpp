#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<pii> vii;
typedef vector<bool> vb;

const int N = 3e5+10; 
const ll INF = 2e9+10;
int a[N];
map<pii, vii> path;
map<pii, ll> costR, costO;

void addCost(auto &m, pii sd, ll p) {
    if (m.count(sd)) m[sd] = min(m[sd], p);
    else m[sd] = p;
}

ll getCost(auto &m, pii sd) {
    if (m.count(sd)) return m[sd];
    return INF;
}

ll go(pii x, vii &v, vb &used) {
    queue<int> q;
    int cnt = 0;

    forn(i, si(v)) {
        if (used[i]) continue;

        if (v[i] == x) q.push(i);
        else if (!q.empty()) {
            int j = q.front(); q.pop();
            used[j] = used[i] = true;
            cnt++;
        }
    }

    return getCost(costR, x)*cnt;
}

ll solve(pii x, vii &v) {
    pii xr = {x.snd, x.fst};
    ll cost = 0;
    vb used(si(v));

    cost += go(x, v, used);
    cost += go(xr, v, used);
    forn(i, si(v)) if (!used[i]) cost += getCost(costO, v[i]);

    return cost;
}

int main() {
	fastio;
	
    int _, n; cin >> _ >> n;
    forn(i, n) cin >> a[i];    
    int m; cin >> m;
    while (m--) {
        int s, d, p; char t; cin >> s >> d >> t >> p;
        if (t == 'O') addCost(costO, {s,d}, p); 
        else addCost(costR, {s,d}, p);
    }

    // minimizo si aba <= ab + ba
    for (auto it : costR) {
        pii x; int c; tie(x, c) = it;
        costO[x] = min(getCost(costO, x), costR[x]);
    }
    // minimizo si ab + ba <= aba
    for (auto it : costO) {
        pii x; int c; tie(x, c) = it; pii xr = {x.snd, x.fst};

        if (costO.count(x) && costO.count(xr))
            costR[x] = min(getCost(costR, x), costO[x] + costO[xr]);
    }
	
    // armo vectores para cada ab
    forn(i, n-1) {
        int s = a[i], d = a[i+1];
        pii sdo = {min(s,d), max(s,d)}; 
        
        path[sdo].pb(s,d);
    }

    // calc ans
    ll ans = 0;
    for (auto it : path) {
        pii sdo; vii v; tie(sdo, v) = it; pii sdor = {sdo.snd, sdo.fst};
        ans += min(solve(sdo, v), solve(sdor, v));
    }
    cout << ans << endl;

	return 0;
}
