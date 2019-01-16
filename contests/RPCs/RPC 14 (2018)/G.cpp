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

const int N = 5e5+10, INF = 1e9;
ll a[N];

int main() {
	fastio;
	
    int n, m; 
    while (cin >> n >> m) {
        fill(a, a+N, 0);

        forn(i, n) {
            int q, x, y; cin >> q >> x >> y;
            a[x] += q; a[y+1] -= q;
        }

        ll mx = -INF, cant = 0; int best;
        forn(p, 5e5+1) {
            cant += a[p];

            ll win = cant*(p-m);
            if (win >= mx) {
                mx = win;
                best = p;
            }
        }

        cout << best << endl;
    }
	
	return 0;
}
