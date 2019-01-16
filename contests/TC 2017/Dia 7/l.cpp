//
// CUIDADO CON FACTORIZAR 1

#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

tint mul(tint a, tint b, tint mod) { 
    tint ret = 0; 
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    } 
    return ret; 
}

tint mpow2(tint x, tint y, tint mod) {
    tint ret = 1;
    while (y) {
        if (y&1) 
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}



bool isPrime(tint p) { // implements by miller-babin
	if (p == 2)	return 1;
    if (p < 2 || !(p&1)) return 0;
    
    tint q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))	q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    
    return 1;
}

tint llgcd(tint x, tint y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    tint t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}



tint pollard_rho(tint n, tint c) {
    tint x = 2, y = 2, i = 1, k = 2, d;
    
    //cerr << n << ' ' << c << endl;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = llgcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}


void llfactorize(tint n, vector<tint> &f) {
    if (n == 1)	
        return ;
        
    if (isPrime(n)) {
        f.push_back(n);
        return ;
    }

    tint d = n;
    for (int i = 2; d == n; i++)
		d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}

const tint MOD = 1e9+7;



int main() {
	//ios_base::sync_with_stdio(false); 
	//cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	tint n;
	cin >> n;
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	vector<tint> fact;
	llfactorize(n, fact);
	
	tint res = 1;
	tint pre = fact[0];
	tint exp = 1;
	forsn(i, 1, si(fact)) {
		if (fact[i] == pre) exp++;
		else {
			//cerr << pre << ' ' << exp << endl;
			res = (res * (((exp+1)*(exp+2))/2)) % MOD;
			pre = fact[i];
			exp = 1;
		}
	}
	res = (res * (((exp+1)*(exp+2))/2)) % MOD;
	//cerr << pre << ' ' << exp << endl;
	
	cout << res << endl;

	return 0;
}
