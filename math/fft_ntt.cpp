// N must be power of 2 !!
using tf = ll;
using poly = vector<tf>;
// FFT
struct CD {
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);
// NTT
// M-1 needs to be a multiple of N !!
// tf TIENE que ser ll
// big mod and primitive root for NTT:
/*
const tf M=2305843009255636993,RT=5;
struct CD {
	tf x;
	CD(tf _x):x(_x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mul(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(add(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(sub(a.x,b.x));}
vector<tf> rts(N+9,-1);
CD root(int n, bool to_inv){
	tf r=rts[n]<0?rts[n]=pot(RT,(M-1)/n):rts[n];
	return CD(to_inv?inv(r):r);
}
*/
CD cp1[N+9],cp2[N+9];
int R[N+9];
void dft(CD* a, int n, bool to_inv){
	forn(i,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(to_inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,to_inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(to_inv)forn(i,n)a[i]/=n; // FFT
	//if(to_inv){ // NTT
	//	CD z(inv(n));
	//	forn(i,n)a[i]=a[i]*z;
	//}
}
poly multiply(poly& p1, poly& p2){
	int n=si(p1)+si(p2)+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forn(i,m){R[i]=0;forn(j,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forn(i,m)cp1[i]=0,cp2[i]=0;
	forn(i,si(p1))cp1[i]=p1[i];
	forn(i,si(p2))cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	forn(i,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	forn(i,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	//forn(i,n)res.pb(cp1[i].x); // NTT
	return res;
}
