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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const long double EPS=1e-9;
struct pto{
	long double x, y;
	pto(long double x=0, long double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(long double a){return pto(x+a, y+a);}
	pto operator*(long double a){return pto(x*a, y*a);}
	pto operator/(long double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	long double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	long double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	long double norm(){return sqrtl(x*x+y*y);}
	long double norm_sq(){return x*x+y*y;}
};
long double dist(pto a, pto b){return (b-a).norm();}
long double dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

long double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);}

//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, long double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}
//stores convex hull of P in S, CCW order
//left must return >=-EPS to delete collinear points!
void chull(vector<pto>& P, vector<pto> &S){
	S.clear();
	sort(P.begin(), P.end());//first x, then y
    P.erase(unique(all(P)),P.end());
	forn(i, si(P)){//lower hull
		while(si(S)>= 2 && S[si(S)-1].left(S[si(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
	int k=si(S);
	dforn(i, si(P)){//upper hull
		while(si(S) >= k+2 && S[si(S)-1].left(S[si(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
}

int main() {
	fastio;

	
    int n;
    cin >> n;
    vector<pto>P;
    pto p(0,0);
    long double res = 0.0;
    string s;
    cin >> s;
    forn(i,n){
        if(s[i] == 'S'){
            P.pb(p+pto(1,0));
            P.pb(p+pto(1,1));
            P.pb(p+pto(0,1));
            P.pb(p);
        }
        else if(s[i]=='C'){
            if(i==0||i==n-1){
                if(n==1)res=acos(-1)-1;
                else res+=0.5*acos(-1)-1;
            }
            P.pb(p+pto(0.5,0));
            P.pb(p+pto(0.5,1));
            pto c = p+pto(0.5,0.5);
            #define ARC 64.0
            if(i!=0){
                pto rot = vec(0,0.5);
                forsn(j,1,ARC){
                    rot = rotate(rot,acos(-1)/ARC);
                    P.pb(c+rot);
                }
            }
            if(i!=n-1){
                pto rot = vec(0,-0.5);
                forsn(j,1,ARC){
                    rot = rotate(rot,acos(-1)/ARC);
                    P.pb(c+rot);
                }
            }
        }
        else if(s[i]=='T'){
            P.pb(p);
            P.pb(p+pto(1,0));
            P.pb(p+pto(0.5,sqrtl(0.75)));
        }
        p = p+pto(1,0);
    }

    vector<pto> ch;
    chull(P,ch);
    if(si(ch)>2)res+= dist(ch.front(),ch.back());
    forsn(i,1,si(ch)){
        res+= dist(ch[i],ch[i-1]);
    }

    cout << fixed << setprecision(7) << res << endl;

    //for(pto pt:P)cerr << "(" <<  pt.x << "," << pt.y << ") ";
    //cerr << endl;
    //for(pto pt:ch)cerr << "(" << pt.x << "," << pt.y << ") ";
    //cerr << endl;
	
	return 0;
}
