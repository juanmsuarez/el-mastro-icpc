
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
using vii = vector<pii>;
using ll = long long;

const int N = 1e6;
vii v;
int cnt, len[N], sum[N], sz[N];
bool on[N];

void advance(int i) {
    int ind, t; tie(ind, t) = v[i];

    if (sum[ind] == 0 && len[ind] == sz[ind]) cnt--;

    if (len[ind] != sz[ind]) len[ind]++;
    sum[ind] += t;
    if (sum[ind] < 0) sum[ind] = 0, len[ind] = 0;

    if (sum[ind] == 0 && len[ind] == sz[ind]) cnt++;
}

int main() {
	fastio;
	
    int n;
    cin >> n;
    forn(i, n) {
        char c; int t; cin >> c >> t;
        v.pb(t-1, c == 's' ? 1 : -1);
        sz[t-1]++;
    }

    forn(i, n) advance(i);
    pii ans = {0, 0};
    forn(i, n) ans = max(ans, {cnt, -i}), advance(i);

    cout << -ans.snd+1 << ' ' << ans.fst << endl;
	
    return 0;
}
