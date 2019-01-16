#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define dforn(i, n) dforsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXK = 18, MAXN = (1<<MAXK)+10, MOD = 1e9+7;
int a[MAXN], fact[MAXN], invfact[MAXN];

int mult(int a, int b) { return (ll)a*b%MOD; }
int add(int a, int b) { return a+b>=MOD ? a+b-MOD : a+b; }
ll pot(ll b, ll e){ // O(log e)
	if(!e) return 1;
	ll q = pot(b, e/2); q = (q * q) % MOD;
	return (e % 2 ? (b * q) % MOD : q);
}
int inv(int x){ return pot(x, MOD-2);}
int comb(int n, int m) {
    if (n < m) return 0;
    return mult(mult(fact[n], invfact[n-m]), invfact[m]);
}

int main() {
    fastio;

    int k; cin >> k;
    int n = 1<<k; dforn(i, n) cin >> a[i]; // leo alreves porque pense que ganaba mas grande
    fact[0] = 1; invfact[0] = inv(fact[0]);
    forsn(i, 1, n+1) fact[i] = mult(i, fact[i-1]), invfact[i] = inv(fact[i]);

    int ans = 0;
    forsn(h, 1, k+1) {
        int leaves = 1<<(h-1), nodeAns = 0, acum = 0, 
            total = mult(comb(n, 2*leaves), fact[2*leaves]),
            invtotal = inv(total);

        dforn(i, n) {
            int valid1 = mult(fact[leaves], comb(i, leaves-1)),
                prob = mult(valid1, invtotal);
            nodeAns = add(nodeAns, mult(mult(prob, a[i]), acum));

            int valid2 = mult(fact[leaves], comb(i-leaves, leaves-1));
            acum = add(acum, mult(valid2, a[i]));
        } 
        nodeAns = mult(2, nodeAns);

        int nodes = 1<<(k-h);
        ans = add(ans, mult(nodes, nodeAns));
    }
    cout << ans << endl;

    return 0;
}
