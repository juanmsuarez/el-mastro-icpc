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

const int N = 1e4;
bool status[N][N]; // updates[b - a][pos]

int main() {
	fastio;
	
    int n, m, q; cin >> n >> m >> q;

    forn(_, m) {
        int k, a, b; cin >> k >> a >> b; a--, b--;
        status[b - a][a] ^= true;
        status[b - a][a + k] ^= true;
    }

    forn(i, N) forsn(j, 1, N) status[i][j] ^= status[i][j - 1];

    forn(_, q) {
        int l, r; cin >> l >> r; l--, r--; if (l > r) swap(l, r);
        cout << (status[r - l][l] ? "SI" : "NO") << endl;
    }
	
	return 0;
}
