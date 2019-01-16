#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
#define M_PI (3.14159265358979323846)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

//~ typedef complex<double> base; //menos codigo, pero mas lento
//elegir si usar complejos de c (lento) o estos
struct base{
    double r,i;
    base(double r=0, double i=0):r(r), i(i){}
    double real()const{return r;}
    void operator/=(const int c){r/=c, i/=c;}
};
base operator*(const base &a, const base &b){
    return base(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);}
base operator+(const base &a, const base &b){
    return base(a.r+b.r, a.i+b.i);}
base operator-(const base &a, const base &b){
    return base(a.r-b.r, a.i-b.i);}
vector<int> rev; vector<base> wlen_pw;
inline static void fft(base a[], int n, bool invert) {
    forn(i, n) if(i<rev[i]) swap(a[i], a[rev[i]]);
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*M_PI/len * (invert?-1:+1);
		int len2 = len>>1;
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
        forsn(i, 1, len2) wlen_pw[i] = wlen_pw[i-1] * wlen;
		for (int i=0; i<n; i+=len) {
			base t, *pu = a+i, *pv = a+i+len2,  *pu_end = a+i+len2, *pw = &wlen_pw[0];
			for (; pu!=pu_end; ++pu, ++pv, ++pw)
				t = *pv * *pw, *pv = *pu - t,*pu = *pu + t;
		}
	}
	if (invert) forn(i, n) a[i]/= n;}
inline static void calc_rev(int n){//precalculo: llamar antes de fft!!
    wlen_pw.resize(n), rev.resize(n);
    int lg=31-__builtin_clz(n);
    forn(i, n){
		rev[i] = 0;
        forn(k, lg) if(i&(1<<k)) rev[i]|=1<<(lg-1-k);
    }}
inline static void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    int n=1; while(n < max(si(a), si(b))) n <<= 1; n <<= 1;
    calc_rev(n);
	fa.resize (n),  fb.resize (n);
	fft (&fa[0], n, false),  fft (&fb[0], n, false);
	forn(i, n) fa[i] = fa[i] * fb[i];
	fft (&fa[0], n, true);
	res.resize(n);
    forn(i, n) res[i] = int (fa[i].real() + 0.5); }
void toPoly(const string &s, vector<int> &P){//convierte un numero a polinomio
    P.clear();
    dforsn(i,0, si(s)) P.pb(s[i]-'0');}


void print(vi &v) {
    forn(i, si(v)) cerr << v[i] << ' ';
    cerr << endl;
}

int main() {
    fastio;

    string s;
    cin >> s;
    int n = si(s);

    s.erase(s.begin(), find(all(s), 'B'));
    //cerr << "q" << s << endl;

    vector<int> a, b, c;

    for (char c : s) {
        a.pb(c == 'A');
        b.pb(c == 'B');
    }
    reverse(all(b));

    //print(a);
    //print(b);

    multiply(a, b, c);

    //print(c);
    c.erase(c.begin(), c.begin() + si(b));
    c.erase(c.begin()+max(0,si(s)-1), c.end());
    //print(c);
    forn(i, n-1)
        if (i < si(c)) cout << c[i] << endl;
        else cout << 0 << endl;

    return 0;
}
