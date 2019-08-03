#include <bits/stdc++.h> using namespace std; #define forn(i,n) for(int i=0;i<int(n);i++) #define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
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
typedef long long int ll;

const int MAXN = 100+10;
bool a[MAXN][MAXN];

int main() {
    fastio;

    freopen("class.in", "r", stdin);
    freopen("class.out", "w", stdout);

    int n, r, c;
    cin >> n >> r >> c;

    n--;
    a[0][0] = true;

    int p = 1;;
    while (n >= 2 && p < r && p < c) {
            a[p][0] = true;
            a[0][p] = true;

            p++;
            n -= 2;
    }

    forn(i, r) forn(j, c) 
        if (n > 0 && a[i][j] == false){
            a[i][j] = true;
            n--; 
        }

    int f1 = 0, f2 = 0;
    forn(i, r) {
        int cnt = 0;
        forn(j, c)
            if (a[i][j]) cnt++;
        f1 = max(f1, cnt);
    }
    forn(j, c) {
        int cnt = 0;
        forn(i, r)
            if (a[i][j]) cnt++;
        f2 = max(f2, cnt);
    }

    cout << min(f1, f2);
    forn(i, r) {
        cout << endl;
        forn(j, c) cout << (a[i][j] ? '#' : '.');
    }

    return 0;
}
