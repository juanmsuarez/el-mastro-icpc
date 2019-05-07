template<class T> T gcd(T a,T b){return b==0?a:gcd(b,a%b);}

struct frac{
	int p,q;
	frac(int p=0, int q=1):p(p),q(q) {norm();}
	void norm(){
		int a = gcd(p,q);
		p/=a, q/=a;
		if(q < 0) q=-q, p=-p;}
	frac operator+(const frac& o){
		int a = gcd(q,o.q);
		return frac(add(mul(p,o.q/a), mul(o.p,q/a)), mul(q,o.q/a));}
	frac operator-(const frac& o){
		int a = gcd(q,o.q);
		return frac(sub(mul(p,o.q/a), mul(o.p,q/a)), mul(q,o.q/a));}
	frac operator*(frac o){
		int a = gcd(q,o.p), b = gcd(o.q,p);
		return frac(mul(p/b,o.p/a), mul(q/a,o.q/b));}
	frac operator/(frac o){
		int a = gcd(q,o.q), b = gcd(o.p,p);
		return frac(mul(p/b,o.q/a), mul(q/a,o.p/b));}
	bool operator<(const frac &o) const{return ll(p)*o.q < ll(o.p)*q;}
	bool operator==(frac o){return p==o.p && q==o.q;}
	bool operator!=(frac o){return p!=o.p || q!=o.q;}
};
