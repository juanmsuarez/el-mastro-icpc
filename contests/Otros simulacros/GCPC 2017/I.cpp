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

const int MAXN = 300000+10, MAXM= 15;
int memo[MAXN][MAXM];

int n,m;
vi seq;

int dp(int i,int j){
    if(i==n)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    int &res = memo[i][j]=0;

    if(!j)res = seq[i] + dp(i+1,m-1);
    res = max(res,dp(i+1,max(0,j-1)));
    return res;
}

int main() {
	fastio;
    fill (memo[0],memo[MAXN],-1);
	
    cin >> n >> m;
    seq = vi(n);
    forn(i,n)cin >> seq[i];
	
    cout << dp(0,m) << endl;
	
	return 0;
}
