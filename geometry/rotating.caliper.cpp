#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); ++it)
#define dforn(i, n) for(int i = ((int) n) - 1; i >= 0; i--)
#define db(v) cerr << #v << " = " << v << endl
#define pb push_back
typedef long long ll;

struct dot{
    ll x, y;
    dot(ll x = 0, ll y = 0):x(x), y(y){}
    dot operator-(const dot b)const {return dot(x-b.x, y-b.y);}
    ll operator*(const dot b)const {return x*b.x + y*b.y;}
    ll operator^(const dot b)const {return x*b.y - y*b.x;}
    bool left(dot q, dot r){return ((q - *this)^(r - *this)) > 0;}
};
bool operator <(dot a, dot b){// first by x, then by y
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
double norm(dot A){return sqrt(A.x*A.x + A.y*A.y);}
double dist(dot A, dot B, dot E){ // distance from point E to segment AB
    return fabs((double)((A - E)^(B - E)) / norm(A-B));
}

void CH(vector<dot> &P, vector<dot> &S){
    S.clear();
    sort(P.begin(), P.end());
    forn(i, P.size()){
        while(S.size()>= 2 && S[S.size()-1].left(S[S.size()-2], P[i]))S.pop_back();
        S.pb(P[i]);
    }
    S.pop_back();
    int k = S.size();
    dforn(i, P.size()){
        while((int)S.size() >= k+2 && S[S.size()-1].left(S[S.size()-2], P[i]))S.pop_back();
        S.pb(P[i]);
    }
    S.pop_back();
}

double RotCaliper(vector<dot> &P){ // To find minimum aperture
    vector<dot> C; CH(P, C); //Rotating caliper is to be run in the Convex Hull of a polygon
    int p1 = 1, p2, n = C.size();
    double ans = -1;
    forn(i, n)if(dist(C[0], C[1], C[i]) > ans)p2 = i, ans = dist(C[0], C[1], C[i]); //This remains the same
    do{ dot AB = C[p1] - C[(p1+n-1)%n];
        dot F = C[(p1+1)%n] - C[p1], S = C[p2] - C[(p2+1)%n];
        if((F^S) < 0)swap(p1, p2);
        p1 = (p1+1)%n;
        ans = min(ans, dist(C[p1], C[(p1+n-1)%n], C[p2]));//To find maximum, change min to max.
    }while(p1 != 1);                                      //Can also can be changed to find correspondent base
    return ans;
}

int n;
vector<dot> P;

int main(){
	int cs = 0;
	while(cin >> n && n){
        P.resize(n);
        forn(i, n)cin >> P[i].x >> P[i].y;
        printf("Minimum caliper aperture: %.7f\n", ++cs, RotCaliper(P));
	}
	return 0;
}
