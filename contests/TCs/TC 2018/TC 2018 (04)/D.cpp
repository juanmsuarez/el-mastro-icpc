#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 4000+10,MOD=1e9+7;
int pascal[MAXN][MAXN];
int bell[MAXN];

int mult(ll a, ll b) {
    return (a*b)%MOD;
}
int add(int a, int b) {
    if (a + b >= MOD) return a + b - MOD;
    return a+b;
}

int main() {
    fastio;

    int n;
    cin >> n;
    pascal[0][0]=1;
    
    forsn(i,1,n+1){
        pascal[i][0]=1;
        forsn(j,1,n){
            pascal[i][j]=add(pascal[i-1][j],pascal[i-1][j-1]);
        }
        pascal[i][i]=1;
    }

    bell[0]=1;
    forsn(i,1,n+1){
        forsn(k,0,i){
            bell[i]=add(bell[i],mult(pascal[i-1][k],bell[k]));
        }
    }

    ll res =0;
    forsn(i,1,n+1){
        res = add(res, mult(pascal[n][i],bell[n-i]));
    }
    cout << res << endl;

    return 0;
}
