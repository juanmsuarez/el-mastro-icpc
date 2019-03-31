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

const int MAXN = 1000+10, MOD = 998244353;

vector<ll> difs; 
ll memo[MAXN][MAXN];

ll dp(int d, int k){
    if(!k)return 1;
    if(d==si(difs))return 0;
    if(memo[d][k]!=-1)return memo[d][k];
    ll &res = memo[d][k];
    
    res= (dp(d+1,k)+(dp(d+1,k-1)*difs[d])%MOD)%MOD;
    return res;
}

int main() {
	fastio;
	
    int n;
    int k;

    cin >> n >> k;

    map<int,int> level;

    forn(i,n){
        int l;
        cin >> l;
        level[l]++;
    }

    for(auto a:level){
        difs.pb(a.snd);
        //cerr <<difs.back() << " a";
    }
    cerr << endl;

    fill(memo[0],memo[MAXN],-1);
    cout << dp(0,k) << endl;
    
	
	return 0;
}

