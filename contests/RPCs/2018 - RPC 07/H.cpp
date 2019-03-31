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
    #define DBG(a) //cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 100+10, INF = 1e9;
int n, m, memoA[MAXN][MAXN], memoB[MAXN][MAXN];

int win(int i1, int j1, int i2, int j2) { 
    if ((i2-i1)%2 == 0 || (j2-j1)%2 == 0) return 0;

    bool color = (i1%2) ^ (j1%2); // white
    return (color ? -1 : 1);
}

int dpB(int i, int j);

int dpA(int i, int j) {
    if (j == -1) return 0;

    int &res = memoA[i][j];
    if (res != -INF) return res;

    forsn(k, 1, n-i+1) 
        res = max(res, win(i, 0, i+k, j+1)-dpB(i+k, j));
    
    //cerr << "A " << i << ' ' << j << ' ' << res << endl;

    return res;
}

int dpB(int i, int j) {
    if (i == n) return 0;

    int &res = memoB[i][j];
    if (res != -INF) return res;

    forsn(k, 1, j+2) {
        //cerr << i << ' ' << j - k + 1 << ' ' << n << ' ' << j+1 << endl;
        //cerr << win(i, j-k+1, n, j+1) << endl;
        res = max(res, win(i, j-k+1, n, j+1)-dpA(i, j-k));
    }

    //cerr << "B " << i << ' ' << j << ' ' << res << endl;

    return res;
}

int main() {
    fastio;

    cin >> m >> n;

    fill(memoA[0], memoA[MAXN], -INF);
    fill(memoB[0], memoB[MAXN], -INF);

    cout << dpA(0, m-1) << endl;

    return 0;
}
