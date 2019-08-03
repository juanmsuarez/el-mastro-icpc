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

const int N = 500+10, M=1e9+7;

inline int mod(int a){ return ((a % M) + M) % M;} // Use for negative numbers (the 2nd modulo is avoidable)
inline int add(int a, int b){ return a+b < M ? a+b : a+b-M; }
inline int sub(int a, int b){ return a-b >= 0 ? a-b : a-b+M; }
inline int mul(int a, int b){ return int(ll(a)*b % M); }
inline int neg(int a){ return add(-a, M); }

int pot(int b, int e){ // O(log e). Puede hacer falta ll
	if(!e) return 1;
	int q = pot(b, e/2); q = mul(q, q);
	return (e % 2 ? mul(b, q) : q);
}

int inv(int x){//O(log x)
	return pot(x, M-2);//si mod es primo
}

int extra[N];

int main() {
	fastio;
	
    int n, m, c; cin >> n >> m >> c;

    int ans = 0, walls = pot(c, n*n);
    forsn(l, 1, m+1) {
        if (m % l == 0) {
            int ways = pot(walls, l);

            forsn(r, 2, m/l+1) 
                extra[l*r] = add(extra[l*r], sub(ways, extra[l])); 

            ans = add(ans, mul(m/l, sub(ways, extra[l])));
        }
    }    

    ans = mul(ans, inv(m));

    cout << ans << endl;
	
	return 0;
}
