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

const int N = 2e3+10;
int memo[N];

int mex(vi &v) {
    sort(all(v));

    int k = 0;
    for (int x : v) {
        if (x > k) return k;
        else if (x == k) k++;
    }

    return k;
}

int dp(int n) {
    int &res = memo[n];
    if (res != -1) return res;

    vi v;
    forsn(k, 1, n) {
        int cant = n/k, resto = n%k;
        v.pb(dp(resto) ^ (cant%2 == 0 ? 0 : dp(k)));
    }

    return res = mex(v);
}

int main() {
	fastio;

    fill(memo, memo+N, -1);
	
    int n; cin >> n;
    
    int ans = 0;

    forn(i, n) {
        int p; cin >> p;
        ans ^= dp(p);
    }    

    cout << (ans > 0 ? "First" : "Second") << endl;
	
	return 0;
}
