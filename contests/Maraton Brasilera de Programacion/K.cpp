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

int main() {
	fastio;

    ll n; cin >> n; n++;

    ll height = 4;
    while (height < n) height *= 2;

    ll ans = 1;
    while (height > 4) {
        height /= 2;

        if (n > height) ans *= 2, n -= height;
    }

    if (n == 2 || n == 3) ans *= 2;
    else if (n == 4) ans *= 4;

    cout << ans << endl;
	
	return 0;
}

