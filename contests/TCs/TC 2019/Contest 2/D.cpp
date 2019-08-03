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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const double EPS = 1e-5;

namespace Simplex {
    vi X,Y;
    vector<vector<double> > A;
    vector<double> b,c;
    double z;
    int n,m;
    void pivot(int x,int y){
        swap(X[y],Y[x]);
        b[x]/=A[x][y];
        forn(i,m)if(i!=y)A[x][i]/=A[x][y];
        A[x][y]=1/A[x][y];
        forn(i,n)if(i!=x&&abs(A[i][y])>EPS){
            b[i]-=A[i][y]*b[x];
            forn(j,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
            A[i][y]=-A[i][y]*A[x][y];
        }
        z+=c[y]*b[x];
        forn(i,m)if(i!=y)c[i]-=c[y]*A[x][i];
        c[y]=-c[y]*A[x][y];
    }
    pair<double,vector<double> > simplex( // maximize c^T x s.t. Ax<=b, x>=0
            vector<vector<double> > _A, vector<double> _b, vector<double> _c){
        // returns pair (maximum value, solution vector)
        A=_A;b=_b;c=_c;
        n=si(b);m=si(c);z=0.;
        X=vi(m);Y=vi(n);
        forn(i,m)X[i]=i;
        forn(i,n)Y[i]=i+m;
        while(1){
            int x=-1,y=-1;
            double mn=-EPS;
            forn(i,n)if(b[i]<mn)mn=b[i],x=i;
            if(x<0)break;
            forn(i,m)if(A[x][i]<-EPS){y=i;break;}
            assert(y>=0); // no solution to Ax<=b
            pivot(x,y);
        }
        while(1){
            int x=-1,y=-1;
            double mx=EPS;
            forn(i,m)if(c[i]>mx)mx=c[i],y=i;
            if(y<0)break;
            double mn=1e200;
            forn(i,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
            assert(x>=0); // c^T x is unbounded
            pivot(x,y);
        }
        vector<double> r(m);
        forn(i,n)if(Y[i]<m)r[Y[i]]=b[i];
        return mp(z,r);
    }
};

struct pto { 
    double x, y; 
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	double norm(){return sqrt(x*x+y*y);}
};
double dist(pto a, pto b){return (b-a).norm();}

int main() {
	fastio;
	
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pto> centers(n); for (auto &p : centers) cin >> p.x >> p.y;

        vector<vector<double>> A; vector<double> b;
        forn(i, n) {
            int j = (i+1)%n;

            vector<double> eq(n, 0); eq[i] = -1, eq[j] = -1;
            A.pb(eq); 

            b.pb(-dist(centers[i], centers[j]));
        }
        forn(i, n) forsn(j, i+1, n) if ((i+1)%n != j && (j+1)%n != i) {
            vector<double> eq(n, 0); eq[i] = 1, eq[j] = 1;
            A.pb(eq); 

            b.pb(dist(centers[i], centers[j]));
        }

        vector<double> c(n, 0);
        vector<double> sol = Simplex::simplex(A, b, c).snd;
        for (double r : sol) cout << fixed << setprecision(10) << r << endl;
    }
	
	return 0;
}
