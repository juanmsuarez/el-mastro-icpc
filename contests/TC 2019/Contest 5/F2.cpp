#pragma GCC optimize("O3")
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
#define snd SEC
#define fst first
#define endl '\n'
#define div _div
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int M = 1e9+7;

typedef unsigned long long ull;
ull mulmod(ull a, ull b, ull m){ // 0 <= a, b < m
   long double x; ull c; ll r;
   x = a; c = x * b / m;
   r = (ll)(a * b - c * m) % (ll)m;
   return r < 0 ? r + m : r;
}

int add(int a, int b) { return a+b >= M ? a+b-M : a+b; }
int sub(int a, int b) { return a-b < 0 ? a-b+M : a-b; }
int mul(int a, int b) { return mulmod(a, b, M); }
int pot(int a, int e) { 
    int res = 1;
    while (e) {
        if (e&1) res = mul(res, a);
        a = mul(a, a);
        e >>= 1;
    }
    return res;
}
int inv(int x){ return pot(x, M-2); } // M must be prime
int div(int a, int b) { return mul(a, inv(b)); }
int normal(int a){ return ((a % M) + M) % M;}

int evalInterpolation(const vector<int> &y, int x) { // {0, y[0]}, ...
    int ans = 0;
    int k = 1;
    forsn(j, 1, si(y)) {
        if (x == j) return y[j];
        k = mul(k, normal(x - j));
        k = div(k, normal(0 - j));
    }
    forn(i, si(y)) {
        ans = add(ans, mul(y[i], k));
        if (i + 1 >= si(y)) break;
        k = mul(k, div(normal(x - i), normal(x - (i + 1))));
        k = mul(k, div(normal(i - (si(y) - 1)), normal(i + 1)));
    }
    return ans;
}

int main() {
	fastio;

    ll n; int k; cin >> n >> k;

    // polinomio de grado k+1
    // encuentro k+2 puntos
    int samples = k+2;
    vi y(samples+1);
    forsn(j, 1, samples+1) y[j] = add(y[j-1], pot(j,k));
    y.erase(y.begin());

    cout << evalInterpolation(y, (n % M)-1) << endl;

	return 0;
}
