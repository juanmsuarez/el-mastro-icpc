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

const int INF = 1e9;

typedef pair<int,pair<int,int>> ans;

ans f(vi v) {
    int n = si(v), best = 0, bests = INF, beste = INF;

    int start = 0, cur = 0;
    forn(i, n) {
        if (cur < 0) { start = i; cur = 0; }

        cur += v[i];

        if (cur > best) {
            best = cur;
            bests = start;
            beste = i;
        }
    }

    return mp(best, mp(-bests, -beste));
}

int main() {
	fastio;
	
    string s; cin >> s;
    int n = si(s);
   
    vi v(n), w(n);
    forn(i, n) {
        v[i] = s[i] == 'R' ? 1 : -1;
        w[i] = s[i] == 'R' ? -1 : 1;
    }

    ans a = max(f(v), f(w));
    cout << -a.snd.fst+1 << ' ' << -a.snd.snd+1 << endl;
	
	return 0;
}
