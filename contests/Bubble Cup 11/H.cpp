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

int main() {
	fastio;
	
    int n; cin >> n;
    
    map<int,int> c;
    ll ans = 0;
    while (n--) {
        string s; cin >> s;

        int mask = (1<<26)-1; for (char ch : s) mask ^= 1<<(ch-'a');

        ans += c[mask];
        forn(i, 26) ans += c[mask^(1<<i)];

        c[mask]++;
    }    
    cout << ans << endl;
	
	return 0;
}
