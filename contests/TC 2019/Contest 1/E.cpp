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

const int N = 1e5, M = 1e9+7;
int dp[N+1];

int add(int a, int b) {
    return a + b >= M ? a + b - M : a + b;
}

int main() {
	fastio;
	
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];

    dp[0] = 1;
    forn(i, n) {
        int num = a[i];

        vi divs;
        for (int d = 1; d * d <= num; d++) if (num % d == 0) {
            divs.pb(d);
            if (d * d != num) divs.pb(num / d);
        }
        sort(all(divs));

        dforn(j, si(divs)) {
            int d = divs[j];
            if (d <= N) dp[d] = add(dp[d], dp[d-1]);
        }
    }

    int ans = 0;
    forsn(i, 1, n+1) ans = add(ans, dp[i]);
    cout << ans << endl;
	
	return 0;
}
