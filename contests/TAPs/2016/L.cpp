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

int main() {
	fastio;
	
    int n,k; cin >> n >> k;
    int x,p,pp = -1; cin >> p;
    bool ok = true, down = false;
    forsn(i,1,k){
        cin >> x;
        if(x < p) down = true;
        if(x == p || x == pp || (down && x > p) || abs(x-p) > 2 || (p == 1 && x == 2) || (p == 2 && x == 1)) ok = false;
	    pp = p, p = x;
    }
    cout << (ok ? "S" : "N") << endl;
	return 0;
}
