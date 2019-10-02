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
using vii = vector<pii>;
using vb = vector<bool>;

int main() {
	fastio;
	
    int n, m, q; cin >> n >> m >> q;
    vii updates;
    forn(_, m) {
        int k, a, b; cin >> k >> a >> b; a--, b--;
        updates.pb(a, b - a);
        updates.pb(a + k, b - a);
    }
    vii queries(q); 
    for (auto &[l, r]: queries) { 
        cin >> l >> r; l--, r--; 
        if (l > r) swap(l, r);
    }

    sort(all(updates));
    vi ind_queries(q); iota(all(ind_queries), 0);
    sort(all(ind_queries), [&queries](int i, int j) { return queries[i] < queries[j]; });

    vb ans(q);
    int ind_update = 0;
    map<int, bool> status;
    for (int ind_query : ind_queries) {
        pii query = queries[ind_query];

        while (ind_update < 2*m && updates[ind_update].fst <= query.fst) {
            status[updates[ind_update].snd] ^= true;
            ind_update++;
        }

        ans[ind_query] = status[query.snd - query.fst];
    }

    for (bool a : ans) cout << (a ? "SI" : "NO") << endl;
	
	return 0;
}
