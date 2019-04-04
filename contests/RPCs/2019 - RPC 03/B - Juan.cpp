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
int lp[N];

int factors(int n) {
    int cant = 0, last = -1;

    while (n != 1) {
        if (lp[n] == last) return 0;

        last = lp[n];
        n /= lp[n];
        cant++;
    }

    return cant;
}

int cant(int d, int a, int b) {
    return b/d - (a-1)/d;
}

int main() {
	fastio;
	
    int a, b, c, d; cin >> a >> b >> c >> d;

    ll ans = (ll)(b-a+1)*(d-c+1);
    forsn(i, 2, N) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2*i; j < N; j += i)
                if (lp[j] == 0)
                    lp[j] = i;
        }

        int fs = factors(i);
        if (fs > 0) ans += (fs%2==0 ? +1 : -1) * (ll) cant(i, a, b) * cant(i, c, d);
    }

    cout << ans << endl;
	
	return 0;
}
