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

const int N = 1e5+10;
int a[N];

int main() {
	fastio;
	
    int n; cin >> n;
    forn(i, n) cin >> a[i];

    ll tot = 0; forn(i, n) tot += a[i];

    int j = 0, matches = 0; 
    ll acum = 0;
    forn(i, n) {
        while (2*acum < tot) {
            acum += a[j];
            j = (j+1)%n;
        }

        matches += 2*acum == tot;
        acum -= a[i];
    }
    matches /= 2;

    cout << (matches >= 2 ? 'Y' : 'N') << endl;

    return 0;
}
