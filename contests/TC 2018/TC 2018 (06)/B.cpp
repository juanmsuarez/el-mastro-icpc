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
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

char digs[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
map<char,int>val;

string p;
int n;

const int MAXBM=(1<<17)+10;
bool memo[MAXBM][16+1][2], vis[MAXBM][16+1][2];
int nxt[MAXBM][16+1][2];

bool dp(int used, int pos,bool same){
    if (pos==n) return !same;

    bool &res = memo[used][pos][same];
    if (vis[used][pos][same]) return res;
    vis[used][pos][same] = true;
    res = false;

    int ind = same?val[p[pos]]:0;
    for(;ind<16;ind++){
        if(!(used&(1<<ind))){
            int nused = (used|(1<<ind)), 
                npos = pos+1; 
            bool nsame = same && ind==val[p[pos]];
            res = dp(nused, npos, nsame);
            if (res) {
                nxt[used][pos][same] = ind;
                //cerr << nused << ' ' << pos << " " << same << " " << ind<<endl;
                return true;
            }
        }
    }

    return false;
}

int main() {
    fastio;

    forn(i,16) val[digs[i]]=i;

    cin >> p;
    n = si(p);

    // ver borde
    int used = 0; bool same = true; 
    if (!dp(used, 0, same)) {
        used |= 2;
        same = false;

        dp(used, 0, same);
        cout << 1;
    }
    
    // borde aca tambien
    forn(pos, n) {
        int d = nxt[used][pos][same];
        used |= (1<<d);
        same &= (d == val[p[pos]]);
        cout << digs[d];
    }
    cout << endl;

    return 0;
}
