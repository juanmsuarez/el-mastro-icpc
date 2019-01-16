#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct point {
	int x, y;

	bool operator <(const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
int cross(const point &o, const point &a, const point &b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<point> chull(vector<point> P)
{
	int n = P.size(), k = 0;
	if (n == 1) return P;
	vector<point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in10.txt","r",stdin); 
	#endif
	
	int n;
	while (cin >> n && n != 0) {
		vector<point> v;
		
		forn(i, n) {
			point p;
			cin >> p.x >> p.y;
			v.pb(p);
		}
		
		int res = 0;
		while (!v.empty()) {
			vector<point> del;
			del = chull(v);
			
			/*
			cout << "quedan " << endl;
			forn(i, si(v)) cout << v[i].x << ' ' << v[i].y << endl;
			cout << "chul" << endl;
			forn(i, si(del)) cout << del[i].x << ' ' << del[i].y << endl;
			*/
			
			forn(i, si(del)) {
				int todel;
				forn(j, si(v)) if (v[j].x == del[i].x && v[j].y == del[i].y) todel = j;
				v.erase(v.begin()+todel);
			}
			res++;
		}
		cout << (res%2==1?"Take this onion to the lab!":"Do not take this onion to the lab!") << endl;
	}

	return 0;
}

