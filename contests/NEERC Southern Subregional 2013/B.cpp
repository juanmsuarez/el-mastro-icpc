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

const double eps = 1e-7;
const int maxn = 3e5;
double c[maxn],r[maxn];

int main() {
    fastio;

	int m,n,d; cin >> m >> n >> d;
	forn(i,m) cin >> c[i];
	forn(i,n) cin >> r[i];
	double res = 0, x = sqrt(d*d - 1);
	double *p = c;
	forn(i,n){
		if(abs(*p-r[i]) > eps){
			if(*p < r[i]){
				double *y = lower_bound(p,c+m,r[i]-x-eps);
				res += *y - *p;
				p = y;
			} else {
				double *y = upper_bound(c,p+1,r[i]+x+eps) - 1;
				res += *p - *y;
				p = y;
			}
		}
	}
	cout << fixed << setprecision(2) << res << endl;
    return 0;
}
