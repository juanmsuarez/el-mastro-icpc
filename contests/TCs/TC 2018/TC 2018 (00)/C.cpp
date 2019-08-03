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

const int MAXN = 1e3+10, INF = 1e9;

struct s {
    int x, y;
    s(int x=0, int y=0) : x(x), y(y) {}
    bool operator != (s o) {
        return x != o.x || y != o.y;
    }
};
const s neutro = {INF, INF};

int n, a[MAXN][MAXN], c2[MAXN][MAXN], c5[MAXN][MAXN];
int nxt[2][MAXN][MAXN];
s memo[MAXN][MAXN];

int get(int a, int b) {
    int cnt = 0;
    while (a%b == 0) {
        a/=b;
        cnt++;
    }
    return cnt;
}

s f(int i, int j, int ind) {
    if (i == n-1 && j == n-1) return {c2[i][j], c5[i][j]};
    if (i >= n || j >= n) return {INF, INF};
    
    s &res = memo[i][j]; 
    if (res != neutro) return res;

    s s1 = f(i+1, j, ind);
    if (s1.x < res.x) {
        res = s1;
        nxt[ind][i][j] = 0;
    }

    s s2 = f(i, j+1, ind);
    if (s2.x < res.x) {
        res = s2;
        nxt[ind][i][j] = 1;
    }

    res = {res.x + c2[i][j], res.y + c5[i][j]};

    return res;
}

int main() {
	fastio;

    bool zero = false;
    cin >> n;
    int zi, zj;
    forn(i, n) forn(j, n) {
        int x;
        cin >> x;
        if (x == 0) {
            zi = i; zj = j;
            zero = true;
        }
        else {
            c2[i][j] = get(x, 2);
            c5[i][j] = get(x, 5);
        }
    } 

    fill(memo[0], memo[n], neutro);
    s t1 = f(0, 0, 0);
    swap(c2, c5);
    fill(memo[0], memo[n], neutro);
    s t2 = f(0, 0, 1);
    //cerr << "End " << endl;

    int mn = INF, ind = -1;

    if (t1.x < t2.x) {
        mn = t1.x;
        ind = 0;
    }
    else {
        mn = t2.x;
        ind = 1;
    }

    if (zero && 1 < mn) {
        cout << 1 << endl;
        int i = 0, j = 0;
        while (i < zi) {
            cout << 'D';
            i++;
        }
        while (j < zj) {
            cout << 'R';
            j++;
        }
        while (i < n-1) {
            cout << 'D';
            i++;
        }
        while (j < n-1) {
            cout << 'R';
            j++;
        }
        cout << endl;
    }
    else {
        cout << mn << endl;
        int i = 0, j = 0;
        while (i != n-1 || j != n-1) {
            //cerr << i << ' ' << j << endl;
            if (nxt[ind][i][j] == 0) {
                cout << 'D';
                i = i+1;
            }
            else {
                cout << 'R';
                j = j+1;
            }
        } 
        cout << endl;
    }

    return 0;
}
