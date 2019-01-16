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

struct pto {
    ll x, y;
    pto(ll x = 0, ll y = 0) : x(x), y(y) {}

	pto operator-(pto a){return pto(x-a.x, y-a.y);}
    ll operator^(pto a){return x*a.y-y*a.x;}
    bool left(pto a){return (a^*this)>0;}
    bool right(pto a){return (a^*this)<0;}
};

const int N = 1e5;
pto p[N];
int n, nxtint[N], preint[N];

#define mod(i) (i+n)%n
#define nxt(i) mod(i+1)

int main() {
	fastio;

    cin >> n;
    forn(i, n) cin >> p[i].x >> p[i].y;

    int j = 1;
    forn(i, n) {
        while ((p[nxt(j)] - p[mod(j)]).left(p[nxt(i)] - p[i])) j++;
        nxtint[i] = j-i;
    }

    j = 1;
    forn(i, n) {
        while (!(p[nxt(j)] - p[mod(j)]).right(p[nxt(i)]-p[i])) j++; 
        preint[i] = j-i;
    }

    ll ans = 0, actsum = 0;

    j = 1;
    forn(i, n) {
        while (j != i+nxtint[i]) { actsum += j+nxtint[mod(j)]; j++; }
        ans += actsum - (ll)(j-i-1)*(i+preint[i]);
        actsum -= i+1+nxtint[nxt(i)];
    }  

    cout << ans/3 << endl;
	
	return 0;
}
