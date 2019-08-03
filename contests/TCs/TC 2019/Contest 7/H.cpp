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

const int N = 1e7+1;
int factors[N], squares[N];

void sieve() {
    for (int n = 2; n < N; n++) if (factors[n] == 0) 
        for (int m = n; m < N; m += n) {
            factors[m]++;
            if ((m / n) % n == 0) squares[m] = true;
        }
}

int main() {
	fastio;

    sieve();
	
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll ans = n;
        for (ll m = 2; m*m <= n; m++)
            if (!squares[m])
                ans -= n / (m*m) * (factors[m] % 2 == 1 ? 1 : -1);

        cout << ans << endl;
    }
	
	return 0;
}
