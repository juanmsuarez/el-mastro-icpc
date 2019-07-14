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

const int N = 1e5+1;
int grundy[N];
vii moves[N];

int main() {
	fastio;
	
    int n; cin >> n;

    forsn(i, 1, n+1) {
        auto mex = [](vii &moves) {
            sort(all(moves));
            int g = 0;
            for (auto [gi, _] : moves)
                if (g < gi) break;
                else if (g == gi) g++;
            return g;
        };

        grundy[i] = mex(moves[i]);

        int j = i, sum = 0, moveGrundy = 0;
        while (j >= 0 && sum + j <= n) {
            moveGrundy ^= grundy[j];
            sum += j; 
            moves[sum].pb(moveGrundy, i-j+1);
            j--;   
        }
    }

    if (grundy[n] == 0) cout << -1 << endl;
    else {
        int res = n;
        for (auto [g, c] : moves[n])
            if (g == 0)
                res = min(res, c);
        cout << res << endl;
    }
	
	return 0;
}
