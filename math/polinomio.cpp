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
		forn(i,m)res[i]=res[i]+c[i];
		forn(i,n)res[i]=res[i]+o.c[i];
		return res;
	}
	poly operator*(tp k){
		poly res(si(c));
		forn(i,si(c))res[i]=c[i]*k;
		return res;
	}
	poly operator*(poly o){
		int m=si(c),n=si(o.c);
		poly res(m+n-1);
		forn(i,m)forn(j,n)res[i+j]=res[i+j]+c[i]*o.c[j];
		return res;
	}
	poly operator-(poly<T> o){return *this+(o*-1);}
	T operator()(tp v){
		T sum(0);
		dforn(i, si(c)) sum=sum*v+c[i];
		return sum;
	}
};
// example: p(x,y)=2*x^2+3*x*y-y+4
// poly<poly<>> p={{4,-1},{0,3},{2}}
// printf("%d\n",p(2)(3)) // 27 (p(2,3))
set<tp> roots(poly<> p){ // only for integer polynomials
	set<tp> r;
	while(!p.c.empty()&&!p.c.back())p.c.pop_back();
	if(!p(0))r.insert(0);
	if(p.c.empty())return r;
	tp a0=0,an=abs(p[si(p.c)-1]);
	for(int k=0;!a0;a0=abs(p[k++]));
	vector<tp> ps,qs;
	forsn(i,1,sqrt(a0)+1)if(a0%i==0)ps.pb(i),ps.pb(a0/i);
	forsn(i,1,sqrt(an)+1)if(an%i==0)qs.pb(i),qs.pb(an/i);
	for(auto pt:ps)for(auto qt:qs)if(pt%qt==0){
		tp x=pt/qt;
		if(!p(x))r.insert(x);
		if(!p(-x))r.insert(-x);
	}
	return r;
}
pair<poly<>,tp> ruffini(poly<> p, tp r){ // returns pair (result,rem)
	int n=si(p.c)-1;
	vector<tp> b(n);
	b[n-1]=p[n];
	dforn(k, n-1) b[k]=p[k+1]+r*b[k+1];
	return mp(poly<>(b),p[0]+r*b[0]);
}
// only for double polynomials
pair<poly<>,poly<> > polydiv(poly<> p, poly<> q){ // returns pair (result,rem)
	int n=si(p.c)-si(q.c)+1;
	vector<tp> b(n);
	dforn(k, n) {
		b[k]=p.c.back()/q.c.back();
		forn(i,si(q.c))p[i+k]-=b[k]*q[i];
		p.c.pop_back();
	}
	while(!p.c.empty()&&abs(p.c.back())<EPS)p.c.pop_back();
	return mp(poly<>(b),p);
}
// for double polynomials
// O(n^2), constante aaaalta
poly<> interpolate(vector<tp> x, vector<tp> y){ 
	poly<> q={1},S={0};
	for(tp a:x)q=poly<>({-a,1})*q;
	forn(i,si(x)){
		poly<> Li=ruffini(q,x[i]).fst;
		Li=Li*(1.0/Li(x[i])); // change for int polynomials
		S=S+Li*y[i];
	}
	return S;
}
// for int polynomials
// O(n), rapido, la posta
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
        k = mul(k, div(normal(i - (si(y) - 1)), normal(i + 1))); // TODO: terminar de explicar esta linea
    }
    return ans;
}
