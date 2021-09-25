#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 3001;

bool quarter[N][N][4];
int grid[N][N];
int area;

int main() {
    fastio;

    int n; cin >> n;
    while (n--) {
        char t; cin >> t;
        int x, y, l; cin >> x >> y >> l;
        x += 1500, y += 1500, l /= 2;

        if (t == 'A') {
            forn(i, l) {
                 grid[x-l][y-l+i]++;
                 grid[x+l][y-l+i]--;
            }
            forn(i, l) {
                 grid[x-l][y+i]++;
                 grid[x+l][y+i]--;
            }
        } 
        else {
            forn(i, l) {
                int row = y-l+i;
                 grid[x-i][row]++;
                 grid[x+i][row]--;
                 quarter[x-1-i][row][0] = true;
                 quarter[x-1-i][row][1] = true;
                 quarter[x+i][row][0] = true;
                 quarter[x+i][row][3] = true;
            }
            forn(i, l) {
                 int row = y+l-1-i;
                 grid[x-i][row]++;
                 grid[x+i][row]--;
                 quarter[x-1-i][row][1] = true;
                 quarter[x-1-i][row][2] = true;
                 quarter[x+i][row][2] = true;
                 quarter[x+i][row][3] = true;
            }
        }
    }

    forn(i, N) forsn(j, 1, N) grid[j][i] += grid[j-1][i];
    forn(i, N) forn(j, N) {
        if (grid[i][j] > 0) area += 4;
        else forn(k, 4) area += quarter[i][j][k];
    }
    
    double ans = double(area) / 4.0;
    cout << fixed << setprecision(2) << ans << endl;
    
    return 0;
}

