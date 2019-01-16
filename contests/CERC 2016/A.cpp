#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 111+10;
char ma[N][N];

typedef vector<char> vc;
typedef vector<vc> window;

void rotate(window &w) {
    int n = si(w), m = si(w[0]);
    window sw = window(m, vc(n));
    forn(i, n) forn(j, m) sw[j][n-1-i] = w[i][j];
    w = sw;
}

int main() {
	fastio;

    int r, c; cin >> r >> c;
    forn(i, r) forn(j, c) cin >> ma[i][j];

    int n = 1, m = 1;
    while (ma[n][1] != '#') n++;
    while (ma[1][m] != '#') m++;
    n--, m--;

    vector<window> ws;
    forn(i, r-1) forn(j, c-1) {
        if (ma[i][j] == '#' && ma[i+1][j] == '#' && ma[i][j+1] == '#') {
            //cerr << "start " << i << ' ' << j << endl;
            window w(n, vc(m));
            forn(di, n) forn(dj, m) {
                int ni = i + 1 + di, nj = j + 1 + dj;
                //cerr << "agrego " << ma[ni][nj] << endl;
                w[di][dj] = ma[ni][nj];
            }
            ws.pb(w);
        }
    }

    int ans = 0;

    forn(a, si(ws)) {
        bool eq = false;

        forn(b, a) {
            int k = 0;
            while (k < 4) {
                eq = true;

                rotate(ws[a]);
                if (si(ws[a]) != n) { k++; continue; }
                forn(i, n) forn(j, m) if (ws[a][i][j] != ws[b][i][j]) eq = false;

                k++;
                if (eq) break;
            }
            while (k < 4) rotate(ws[a]), k++;

            if (eq) break;
        }

        //cerr << a << ' ' << eq << endl;

        if (!eq) ans++;
    }

    cout << ans << endl;
	
	return 0;
}
