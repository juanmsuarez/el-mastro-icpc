#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = "  << a << endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;

int n,t;
const int N = 201;
ll dp[N][N][N], a[N];

ll f(int i, int x, int k){
    //cerr << "At " << i << ' ' << x << ' ' << k << endl;

    if(dp[i][x][k] != -2) return dp[i][x][k];
    if(i == n && x > 0) return -1;
    if(x == 0){
        if(n-i<=t-k)return 0;
        else return -1;
    }
    ll e = f(i+1,x-1,0);
    dp[i][x][k] = max((e == -1 ? -1 : e+a[i]), (k < t ? f(i+1,x,k+1) : -1));
    //cerr <<"dp[" <<i << "][" << x << "][" << k << "] = "<< dp[i][x][k] << endl;
    //cerr << "e = " << e << endl;
    return dp[i][x][k];
}

int main(){
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -2;
    int k,x; cin >> n >> k >> x; t = k-1;
    forn(i,n) cin >> a[i];
    cout << f(0,x,0) << endl;
    //cerr << dp[0][x][0] << endl;
}
