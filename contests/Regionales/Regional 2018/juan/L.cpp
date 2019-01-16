#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;
typedef tree<pii,null_type,greater<pii>,//key,mapped type, comparator
    rb_tree_tag,tree_order_statistics_node_update> set_t;

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
typedef vector<int> vi;
typedef long long ll;

typedef tuple<int, int, int> query;

const int Q = 5e4+10;
query qs[Q];
pii ans[Q];

int maxfactor(int n) {
    int mx = 0;

    for (int d = 2; d*d <= n; d++) {
        if (n % d == 0) mx = d;
        while (n % d == 0) n /= d;
    }
    if (n > 1) mx = n;

    return mx;
}

int main() {
	fastio;
	
    int q; cin >> q;
    forn(i, q) {
        int n, k; cin >> n >> k;
        qs[i] = {n, k, i};
    }

    sort(qs, qs+q);

    set_t s;
    int x = 2, t = 0;
    forn(i, q) {
        int n, k, ind; tie(n, k, ind) = qs[i];

        while (x <= n) s.insert({maxfactor(x++), t++});

        int cant = si(s) - s.order_of_key({k, t}); // ver

        ans[i] = {ind, cant};
    }

    sort(ans, ans+q);
    forn(i, q) cout << ans[i].snd << endl;
	
	return 0;
}
