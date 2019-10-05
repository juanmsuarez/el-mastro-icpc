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

int solve(vii &intervals_a, vii &intervals_b) {
    int ans = 0;
    int j = 0, mx_r = 0;

    for (auto [l_a, r_a] : intervals_a) {
        while (j < si(intervals_b) && intervals_b[j].fst <= l_a) {
            mx_r = max(mx_r, intervals_b[j].snd);
            j++;
        }
        ans = max(ans, min(r_a, mx_r) - l_a);
    }

    return ans;
}

int main() {
	fastio;
	
    int n; cin >> n;
    vii intervals_a, intervals_b; 
    forn(_, n) { 
        char c; int s, e; cin >> c >> s >> e; s--, e--;
        if (c == 'D') intervals_a.pb(s, e); else intervals_b.pb(s, e);
    }

    sort(all(intervals_a));
    sort(all(intervals_b));

    cout << max(solve(intervals_a, intervals_b), solve(intervals_b, intervals_a)) << endl;
	
	return 0;
}
