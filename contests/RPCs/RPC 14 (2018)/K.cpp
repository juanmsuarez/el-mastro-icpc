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

const double INF = DBL_MAX;

int main() {
	fastio;
    
    int n = 6;
	
    vector<double> v(n);
    for (double &d : v) cin >> d;

    double ex = 0;
    forn(i, n) ex += (i+1)*v[i];

    double ans = INF;
    forn(i, n) {
        if (v[i] == 0) continue;

        ex -= (i+1)*v[i];

        double act = (3.5 - ex)/v[i];
        ans = min(ans, abs((i+1) - act));

        ex += (i+1)*v[i];
    }

    cout << fixed << setprecision(3) << ans << endl;
	
	return 0;
}
