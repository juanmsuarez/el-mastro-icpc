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

const int N = 300+1, M = 1e9+7, C = 3;
int n, m, memo[N][N][N]; 
vii conditions[N];

int add(int a, int b) {
    return a + b >= M ? a + b - M : a + b;
}

bool valid(int pos, int last0, int last1, int last2) {
    for (auto lx : conditions[pos]) {
        int l, x; tie(l, x) = lx;
        int cant = (last0 >= l) + (last1 >= l) + (last2 >= l);
        if (cant != x) return false;
    }

    return true;
}

int dp(int last0 = 0, int last1 = 0, int last2 = 0) {
    int pos = max({last0, last1, last2})+1;
    if (pos == n+1) return 1;

    int &res = memo[last0][last1][last2];
    if (res != -1) return res;
    res = 0;

    if (valid(pos, pos, last1, last2))
        res = add(res, dp(pos, last1, last2));
    if (valid(pos, last0, pos, last2))
        res = add(res, dp(last0, pos, last2));
    if (valid(pos, last0, last1, pos))
        res = add(res, dp(last0, last1, pos));

    return res;
}

int main() {
	fastio;

    cin >> n >> m;    
    while (m--) {
        int l, r, x; cin >> l >> r >> x;
        conditions[r].pb(l, x);
    }

    fill(memo[0][0], memo[N][0], -1);
    cout << dp() << endl;
	
	return 0;
}
