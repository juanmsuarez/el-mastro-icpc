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

struct trio{
    int e,p,s;
    trio(int E = 0, int P = 0, int S = 0){
        e = E; p = P; s = S;
    }
};

const int N = 1e6+1;
trio a[N];

int main() {
    fastio;
    int n; cin >> n;
    a[0] = trio(-1,0,0);
    forsn(i,1,n+1){
        int id,o,x; cin >> id >> o;
        int sz = a[id].s;
        if(o == 0){
            cin >> x;
            a[i] = trio(x,id,sz+1);
            cout << sz+1 << endl;
        } else {
            a[i] = trio(sz-1 ? a[a[id].p].e : -1,id,sz ? sz-1 : 0);
            cout << a[id].e << endl;
        }
    }
    return 0;
}
