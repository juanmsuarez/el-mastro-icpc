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

const int MAXN = 3e3+10;
char a[MAXN][MAXN];
bool in[2*MAXN];
int cant[2*MAXN];
map<int, int> m[2*MAXN];

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) forn(j, n) {
        cin >> a[i][j];
        if (a[i][j] != '?') {
            m[i][a[i][j]]++;
            m[n+j][a[i][j]]++;
        }
    }

    queue<int> q;
    forn(i, 2*n) {
        if (si(m[i]) == 1) {
            q.push(i);
            in[i] = true;
        }
    }

    vector<tuple<char,int,char>> ans;
    while (!q.empty()) {
        int ind = q.front(); q.pop();
        char color;

        if (si(m[ind]) == 0) continue;

        forn(k, n) {
            int i = ind < n ? ind : k, j = ind >= n ? ind-n : k,
                other = ind < n ? k+n : k;
            //cerr << i << ' ' << j << ' ';

            //cerr << a[i][j] << endl;

            if (a[i][j] == '?') continue;

            m[other][a[i][j]]--;
            if (m[other][a[i][j]] == 0) m[other].erase(a[i][j]);

            color = a[i][j];
            a[i][j] = '?';
        }
        //cerr << endl;

        m[ind].erase(color);

        forn(k, 2*n) 
            if (si(m[k]) == 1 && !in[k]) {
                in[k] = true;
                q.push(k);
            }

        cant[ind]++;
        ans.pb((ind < n ? 'h' : 'v'), ind%n+1, color);
        //cerr << (ind < n ? 'h' : 'v') << ' ' << ind%n+1 << ' ' << color << endl;
    }

    forn(i, 2*n)
        if (cant[i] == 0) 
            ans.pb(i < n ? 'h' : 'v', i%n+1, 'a');

    reverse(all(ans));
    for (auto t : ans) {
        char x, z; int y; tie(x, y, z) = t;
        cout << x << ' ' << y << ' ' << z << endl;
    }

    return 0;
}
