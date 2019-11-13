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

vector<ll> pol(1, 1);
int m = 1;

void mul(int k) { // pol * (x - k)
    k *= -1;

    pol.pb(0), m++;

    dforn(i, m - 1) pol[i + 1] += pol[i] * k;
}

ll eval_0() { return pol.back(); }

void inv() {
    for (ll &a : pol) a *= -1;
}

int main() {
	fastio;
	
    string s; cin >> s;
    int n = si(s);

    forn(i, n - 1) 
        if (s[i] != s[i + 1])
            mul(2 * (i + 1) + 1);

    if ((eval_0() > 0) != (s[0] == 'H')) inv();

    cout << m - 1 << endl;
    forn(i, m) cout << pol[i] << " \n"[i == m - 1];
	
	return 0;
}
