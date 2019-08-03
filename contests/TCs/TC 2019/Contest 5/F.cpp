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
int inv(int x){ return pot(x, (M-2)); } // M must be prime

using tp = int; // type of polynomial
template<class T=tp>
struct poly {  // poly<> : 1 variable, poly<poly<>>: 2 variables, etc.
	vector<T> c;
	T& operator[](int k){return c[k];}
	poly(vector<T>& c):c(c){}
	poly(initializer_list<T> c):c(c){}
	poly(int k):c(k){}
	poly(){}
	poly operator+(poly<T> o){
		int m=si(c),n=si(o.c);
		poly res(max(m,n));
		forn(i,m)res[i]=add(res[i], c[i]);
		forn(i,n)res[i]=add(res[i], o.c[i]);
		return res;
	}
	poly operator*(tp k){
		poly res(si(c));
		forn(i,si(c))res[i]=mul(c[i],k);
		return res;
	}
	poly operator*(poly o){
		int m=si(c),n=si(o.c);
		poly res(m+n-1);
		forn(i,m)forn(j,n)res[i+j]=add(res[i+j],mul(c[i],o.c[j]));
		return res;
	}
	T operator()(tp v){
		T sum(0);
		dforn(i, si(c)) sum=add(mul(sum,v),c[i]);
		return sum;
	}
};
int t;
// only for double polynomials
poly<> interpolate(vector<tp> x, vector<tp> y){ 
	poly<> q={1},S={0};
	for (tp a:x) q=poly<>({M-a,1})*q;
    int n=si(q.c)-1;
    poly<> b(n);
	forn(i,si(x)){
        b[n-1]=q[n];
        dforn(k, n-1) b[k]=add(q[k+1],mul(x[i],b[k+1]));

		S=S+b*inv(b(x[i]))*y[i];
	}
	return S;
}

int main() {
	fastio;

    t = clock();

    ll n; int k; cin >> n >> k;

    // polinomio de grado k+1
    // encuentro k+2 puntos
    int samples = k+2;
    vi x(samples+1), y(samples+1);
    forsn(j, 1, samples+1) x[j] = j, y[j] = add(y[j-1], pot(x[j],k));
    x.erase(x.begin()), y.erase(y.begin());

    // interpolo
    auto pol = interpolate(x, y);

    // evaluo
    cout << pol(n%M) << endl;

	return 0;
}
