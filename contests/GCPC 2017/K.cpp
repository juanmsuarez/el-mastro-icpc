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
typedef pair<int, string> pis;

const int N = 1e4+10;
pis a[N];

int main() {
	fastio;
	
    int n, d, k; cin >> n >> d >> k;
    forn(i, n) cin >> a[i].snd >> a[i].fst;

    sort(a, a+n, greater<pis>());

    int sum = 0;
    forn(i, k) sum += a[i].fst;

    if (sum >= d) {
        cout << k << endl;
        forn(i, k) cout << a[i].snd << ", YOU ARE FIRED!" << endl;
    }
    else cout << "impossible" << endl;
	
	return 0;
}
