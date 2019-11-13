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

#define lg(n) 31 - __builtin_clz(n)
typedef int T; 
struct RMQ {
    const static int K = 10; // 2^K > N
    T t[K][1 << K];
    T& operator[](int p) { return t[0][p]; }
    T get(int i, int j) { // O(1), [i, j)
        int p = lg(j - i);
        return min(t[p][i], t[p][j - (1 << p)]);
    }
    void build(int n) { // O(n log n)
        forn(p, lg(n)) forn(x, n - (1 << p))
            t[p + 1][x] = min(t[p][x], t[p][x + (1 << p)]);
    }
} rmq;

const int N = 1e3;
bool val[N][N];

int eq_pref[N][N];

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    forn(i, n) forn(j, m) { char c; cin >> c; val[i][j] = c == 'G'; }

    forn(i, n) dforn(j, m) 
        if (j + 1 < m && val[i][j] == val[i][j + 1])
            eq_pref[i][j] = eq_pref[i][j + 1] + 1;
        else
            eq_pref[i][j] = 1;

    int ans = 0;

    forn(j, m) {
        forn(i, n) rmq[i] = eq_pref[i][j];
        rmq.build(n);

        forn(i, n) {
            auto can = [&](int k) { return rmq.get(i, i + k) >= k; };

            int lo = 0, hi = n - i + 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (can(mid)) lo = mid;
                else hi = mid;
            }

            ans = max(ans, lo * lo);
        }
    }

    cout << ans << endl;    
	
	return 0;
}
