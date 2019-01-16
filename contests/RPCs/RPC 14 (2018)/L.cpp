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
typedef vector<pii> vii;

int s;

bool can(int i, int j) {
    return (s % (i+j) == 0 && s / (i+j) > 0)
        || ((s-i)%(i+j) == 0 && (s-i)/(i+j) > 0);
}

int main() {
	fastio;
	
    cin >> s;

    vii ans;
    forsn(i, 2, s+1) {
        if (can(i, i-1)) ans.pb(i, i-1);
        if (can(i, i)) ans.pb(i, i);
    }

    sort(all(ans));
    cout << s << ':' << endl;
    for (pii p : ans) cout << p.fst << ',' << p.snd << endl;
	
	return 0;
}
