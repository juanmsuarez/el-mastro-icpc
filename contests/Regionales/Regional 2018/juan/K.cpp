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

int n;
vi sol;
vector<vi> sols;

void solve(vi &v) {
    if (si(v) == 1) {
        if (v.front() == 0) sols.pb(sol);
        return;
    }

    int dif = v[1] - v[0];

    bool can = true;
    vi a, b;
    map<int,int> match;
    for (int e : v) {
        if (match[e-dif] > 0) {
            match[e-dif]--;
            a.pb(e);
        }
        else {
            match[e]++;
            b.pb(e);
        }
    }

    if (can) {
        sol.pb(-dif);
        solve(a);
        sol.pop_back();

        sol.pb(dif);
        solve(b);
        sol.pop_back();
    }
}

int main() {
	fastio;
	
    cin >> n;
    vi v(1<<n);
    forn(i, 1<<n) cin >> v[i];
    sort(all(v));

    solve(v); 

    for (vi &sol : sols) sort(all(sol));
    sort(all(sols)); sols.erase(unique(all(sols)), sols.end());

    for (vi &sol : sols) 
        forn(i, n) 
            cout << sol[i] << " \n"[i==n-1];
	
	return 0;
}
