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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int K = 17;

#define lg(n) 31 - __builtin_clz(n)
template<class T, class Compare, T INF>
struct RMQ {
    T t[K][1 << K];
    T& operator[](int p){ return t[0][p]; }
    T best(T x, T y) { return Compare()(x, y) ? x : y; }
    T get(int i, int j){ // O(1), [i, j)
        if (i >= j) return INF;
        int p = lg(j-i);
        return best(t[p][i], t[p][j - (1 << p)]);
    }
    void build(int n){ // O(n log n)
        forn(p, lg(n)) forn(x, n - (1 << p))
            t[p + 1][x] = best(t[p][x], t[p][x + (1 << p)]);
    }
};

const int N = 1e5;
const ll INF = 1e18;
int n, lower, upper; 
int dif[N];

ll pref[N + 1];
void calc_pref() { forn(i, n) pref[i + 1] = pref[i] + dif[i]; }
ll sum(int a, int b) { return pref[b] - pref[a]; }

RMQ<ll, less<ll>, INF> rmq_min;
RMQ<ll, greater<ll>, -INF> rmq_max;
void init_rmq() {
    forn(i, n + 1) rmq_min[i] = pref[i];
    forn(i, n + 1) rmq_max[i] = pref[i];
    rmq_min.build(n + 1);
    rmq_max.build(n + 1);
}

pii jump[N][2];
pii find_lower(int start, int wealth) {
    int lo = start, hi = n + 1;

    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;

        ll worst = rmq_min.get(start + 1, mid + 1) - pref[start];

        if (wealth + worst < lower) hi = mid;
        else lo = mid;
    }

    return {hi, 0};
}
pii find_upper(int start, int wealth) {
    int lo = start, hi = n + 1;

    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;

        ll worst = rmq_max.get(start + 1, mid + 1) - pref[start];

        if (wealth + worst > upper) hi = mid;
        else lo = mid;
    }

    return {hi, 1};
}
void calc_jump() {
    forn(i, n) forn(wealth_bound, 2) {
        int wealth = wealth_bound == 0 ? lower : upper;
        jump[i][wealth_bound] = min(find_lower(i, wealth), find_upper(i, wealth));
    }
}

pii kth_jump[N + 2][2][K];
void compose() {
    forn(i, n) forn(wealth_bound, 2) kth_jump[i][wealth_bound][0] = jump[i][wealth_bound];
    kth_jump[n][0][0] = {n, 0};
    kth_jump[n][1][0] = {n, 1};
    kth_jump[n + 1][0][0] = {n + 1, 0};
    kth_jump[n + 1][1][0] = {n + 1, 1};

    forn(k, K - 1) {
        forn(i, n + 2) forn(wealth_bound, 2) {
            pii mid = kth_jump[i][wealth_bound][k]; 
            kth_jump[i][wealth_bound][k + 1] = kth_jump[mid.fst][mid.snd][k];
        }
    }
}

int solve() {
    int b, e, x; cin >> b >> e >> x; b--;

    auto cur = min(find_lower(b, x), find_upper(b, x));
    if (cur.fst > e) return x + sum(b, e);

    dforn(k, K) {
        auto possible_jump = kth_jump[cur.fst][cur.snd][k];
        if (possible_jump.fst <= e) cur = possible_jump;
    }

    return (cur.snd == 0 ? lower : upper) + sum(cur.fst, e);
}

int main() {
	fastio;
	
    cin >> n >> lower >> upper;
    forn(i, n) cin >> dif[i];

    calc_pref();
    init_rmq();

    calc_jump();
    compose();

    int q; cin >> q;
    while (q--) cout << solve() << endl;
	
	return 0;
}
