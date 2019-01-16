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

const int MAXN=18,MAXS=26;

vi delta[MAXN][MAXS];

int main() {
    fastio;
    
    int t;
    cin >> t;
    forn(_,t){
        int n,m,s,k ;
        cin >> n >> m >> s >> k;
        map<char,int> sigma;
        forn(i,s){
            char a;
            cin >>a;
            sigma[a]=i;
        }
        set<int> F;
        forn(i,k){
            int st;
            cin >> st;
            F.insert(st);
        }
        forn(i,m){
            int sx,sy;
            char c;
            cin >> sx >> sy >> c;
            delta[sx][sigma[c]].pb(sy);
        }
        int q;
        forn(i,q){
            string w;
            cin >> w;
            set<int> act,nxt;
        }
    }

    return 0;
}
