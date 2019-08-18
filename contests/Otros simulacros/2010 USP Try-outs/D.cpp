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

typedef int tipo;
struct Fenwick {
    static const int sz = (1 << 10) + 1;
    tipo t[sz][sz];

    void set(int x, int y, tipo val){ // p en [1, sz), O(lg n)
        for (int i = x; i < sz; i += (i & -i))
            for (int j = y; j < sz; j += (j & -j))
               t[i][j] = max(t[i][j], val); 
    }

    tipo get(int x, int y){ // Suma acumulada en [1, p], O(lg n)
        tipo s = 0;
        for (int i = x; i; i -= (i & -i))
            for (int j = y; j; j -= (j & -j))
                s = max(s, t[i][j]);
        return s;
    }
} fen;

int main() {
	fastio;
	
    int n; cin >> n;
    vii ps(n); for (auto &[x, y] : ps) cin >> x >> y;

    int ans = 0;
    for (auto [x, y] : ps) {
        int best = fen.get(x, y);

        fen.set(x, y, best + 1); 

        ans = max(ans, best + 1);
    }

    cout << ans << endl;
	
	return 0;
}
