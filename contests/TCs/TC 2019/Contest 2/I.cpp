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

int M;

int mul(int a, int b) {
    return (ll)a*b%M;
}

int add(int a, int b) {
    return a + b >= M ? a + b - M : a + b;
}

int expmod(int b, ll e){ // O(log e)
	if (!e) return 1;
	int q = expmod(b, e/2); q = mul(q, q);
	return (e & 1 ? mul(b, q) : q);
}

int inv(int x){//O(log x)
	return expmod(x, M-2);
}

ll sum(int n) {
    return (ll)n*(n+1)/2;
}

int main() {
	fastio;
	
    int n, k; cin >> n >> k >> M;

    // identity: k ^ (n*(n+1)/2)
    int identity = expmod(k, sum(n));

    // rotation: k^(n-1) * k^(n-4) * k^(n-7) ... 
    // terms * n - sum_{i=1, i=terms}(3*i-2) = terms * n - 3*sum(terms) + 2*terms
    // terms = (n+1)/3
    // caso especial si ultimo termino es 1 (en realidad 0, (n-1)%3==0): sumar 1
    int terms = (n+1)/3, rotation = expmod(k, (ll)terms*n - 3*sum(terms) + 2*terms + ((n-1)%3==0)*1);

    // reflection: k * k * k^2 * k^2 * k^3 * k^3 + ...
    // 2 * sum(n/2)
    int reflection = expmod(k, 2*sum(n/2) + (n%2)*(n+1)/2);

    // burnside: 1 / 6 * (identity + 2 * rotation + 3 * reflection)
    int burnside = identity;
    burnside = add(burnside, mul(2, rotation));
    burnside = add(burnside, mul(3, reflection));
    burnside = mul(burnside, inv(6));

    cout << burnside << endl;
	
	return 0;
}
