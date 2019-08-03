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

const int MAXN = 200+10;
set<int> s[MAXN];
set<int> interPosta[MAXN][MAXN];

int main() {
    fastio;

    int n;
    cin >> n;

    forn(_, n*(n-1)/2) {
        int x, y, k; cin >> x >> y >> k; x--; y--; 
        if (y < x) swap(x, y);
        forn(_, k) {
            int a;
            cin >> a;
            interPosta[x][y].insert(a);
            s[x].insert(a);
            s[y].insert(a);
        }
    }

    bool can = true;
    forn(x, n)
        forsn(y, x+1, n) {
            set<int> inter;
            for (int a : s[x])
                if (s[y].count(a))
                    inter.insert(a);
            if (inter != interPosta[x][y]) can = false;
        }

    if (can) {
        cout << "Yes" << endl;
        forn(x, n) {
            cout << si(s[x]);
            for (int k : s[x]) cout << ' ' << k;
            cout << endl;
        }
    }
    else cout << "No" << endl;

    return 0;
}
