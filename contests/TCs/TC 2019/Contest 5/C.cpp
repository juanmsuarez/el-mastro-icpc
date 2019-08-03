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

const int N = 50+1;
int s, r, a[N], largest; 
ll comb[N][N];
double memo[N][N][2];

void calcComb() {
    forn(i, N) comb[i][0] = 1;
    forsn(i, 1, N) forsn(j, 1, N) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
}

void init() {
    fill(memo[0][0], memo[N][0], -1);
}

double prob(int rooms, int students, bool done) {
    if (rooms == 0) return students == 0 && done;

    double &res = memo[rooms][students][done];
    if (res != -1) return res;

    res = 0;
    double probHere = 1;
    forn(here, min(students, largest*a[rooms-1])+1) {
        int nrooms = rooms-1, nstudents = students-here;
        int length = (here+a[rooms-1]-1)/a[rooms-1];
        bool ndone = done || length == largest;

        res += comb[students][here]*probHere * prob(nrooms, nstudents, ndone);
        probHere *= 1./r;
    }

    return res;
}

int main() {
	fastio;

    calcComb();
	
    cin >> s >> r; 
    forn(i, r) cin >> a[i];

    double ans = 0;
    for (largest = 1; largest <= s; largest++) {
        init();
        ans += largest*prob(r, s, false);
    }

    cout << fixed << setprecision(9) << ans << endl;
	
	return 0;
}
