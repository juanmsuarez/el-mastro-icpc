// MODNTT-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
// const ll MODNTT = 2305843009255636993;
// const int RT = 5;
// struct for FFT, for NTT is simple (ll with mod operations)
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}

const double pi = acos(-1.0); // FFT
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
//CD root(int n, bool inv){ // NTT
//	ll r=pot(RT,(MODNTT-1)/n); // pot: modular exponentiation
//	return CD(inv?pot(r,MODNTT-2):r);
//}
void dft(CD* a, int n, bool inv){
	forn(i,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for (int m=2;m<=n;m*=2){
		double z = 2*pi/m*(inv?-1:1); // FFT
		CD wi = CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
		for (int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w; a[k]=u+v; a[k2]=u-v; w=w*wi;
			}
		}
	}
	if(inv) forn(i,n)a[i]/=n; // FFT
	//if(inv){ // NTT
	//	CD z(pot(n,MODNTT-2)); // pot: modular exponentiation
	//	forn(i,n)a[i]=a[i]*z;
	//}
}
vi multiply(vi& p1, vi& p2){
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
	vi res;
	n-=2;
	forn(i,n)res.pb((ll)floor(cp1[i].real()+0.5)); // change for NTT
	return res;
}
