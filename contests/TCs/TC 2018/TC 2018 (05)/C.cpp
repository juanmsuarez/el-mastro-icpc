#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
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
typedef long long int tipo;

tipo mcd(tipo a, tipo b){return a?mcd(b%a, a):b;}
struct frac{
	tipo p,q;
	frac(tipo p=0, tipo q=1):p(p),q(q) {/*norm();*/}
	//void norm(){
	//	tipo a = mcd(p,q);
	//	if(a) p/=a, q/=a;
	//	else q=1;
	//	if (q<0) q=-q, p=-p;}
	frac operator+(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
	frac operator-(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
	frac operator*(frac o){
		tipo a = mcd(q,o.p), b = mcd(o.q,p);
		return frac((p/b)*(o.p/a), (q/a)*(o.q/b));}
	frac operator/(frac o){
		tipo a = mcd(q,o.q), b = mcd(o.p,p);
		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));}
	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
	bool operator==(frac o){return p==o.p&&q==o.q;}
};

bool comp(frac a,frac b){
    return a.q-a.p > b.q-b.p;
}

int main() {
    fastio;

    int n;
    cin >> n;
    
    vector<frac> s1(n),s2(n);

    ll num=0,den=0;
    forn(i,n){
        ll p,q;
        cin >> p >> q;
        num+=p;
        den+=q;
        s1[i]=frac(p,q);
        s2[i]=s1[i];
    }

    sort(all(s1));
    sort(all(s2),comp);

    frac resa(num,den),resb(num,den);
    vi sol;
    forn(i,n){
        resa.p-=s1[i].p;
        resa.q-=s1[i].q;
        resb.p-=s2[i].p;
        resb.q-=s2[i].q;
        //cerr << "D:" << endl;
        //cerr << "resa: " << resa.p << " " << resa.q << endl;
        //cerr << "resb: " << resb.p << " " << resb.q << endl;

        if(resa<resb)sol.pb(i+1);
    }
    cout << si(sol) << endl;

    for(auto s:sol){
        cout << s << endl;
    }

    return 0;
}
