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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN=1010;
int memo[MAXN];
int pila[MAXN];
int k;

int mex(vi &seq){
    int m =0;
    while(find(all(seq),m)!=seq.end())m++;
    return m;
}

int grundy(int n){
    if(n==0)return 0;
    if(memo[n]!=-1)return memo[n];
    int &res = memo[n];
    int sz= min(k+1,n);
    vi mov;
    forn(i,sz){
        if (pila[n-1-i] <= n-i)
            mov.pb(grundy(n-i-pila[n-1-i]));
    }
    return res = mex(mov);
}

int main() {
    fastio;

    int p;
    cin >> p >> k;
    int res=0;
    forn(i,p){
        fill(memo,memo+MAXN,-1);
        int n;
        cin >> n;
        forn(j,n)cin >> pila[j];
        res^=grundy(n);
        DBG(memo[n]);
        DBG(res);
    }
    cout << (!res?"Bob will win.":"Alice can win.") << endl;

    return 0;
}
