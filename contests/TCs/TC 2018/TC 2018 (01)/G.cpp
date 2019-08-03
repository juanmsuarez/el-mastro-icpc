#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(i-nt i=(int)(s);i<(int)(n);i++)
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

const int N = 1 << 9;
int t[N][N], p = 0;

void f(int n, int sx, int sy, int x, int y, int c){
    //cerr << "cuad " << sx << ' ' << sy << " special " << x << ' ' << y << " va de " << c << endl;
    p++;
    t[sx+x][sy+y] = c;
    if(n == 2) {
        forn(i,2) forn(j,2) if(i != x || j != y) {
            t[sx+i][sy+j] = p;
            //cerr << "base " << sx+i << ' ' << sy+j << " de " << p << endl;
        }
    }
    else {
        int m = n >> 1;
        int nx = x / m, ny = y / m, mip = p;
        forn(i,2) forn(j,2){

            if(i == nx && j == ny)
                f(m, sx + m*i, sy + m*j, x-m*i, y-m*j, c);
            else
                f(m, sx + m*i, sy + m*j, (i - 1 + m)%m, (j - 1 + m)%m, mip);
        }
    }
}

int main() {
    fastio;

    int n, x, y; cin >> n >> x >> y;
    f(1 << n, 0, 0, x-1, y-1, 0);
    forn(i,1<<n) forn(j,1<<n) {
        cout << t[i][j] << (j == (1<<n)-1 ? '\n' : ' ');
    }
    return 0;
}
