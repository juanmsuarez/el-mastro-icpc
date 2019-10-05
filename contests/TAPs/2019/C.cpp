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
#define left _left
#define right _right
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 2e3;
bool on[N][N];
int left[N][N], right[N][N], bottom[N][N], top[N][N];
int cnt[N][N];

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    forn(i, n) forn(j, m) { char c; cin >> c; on[i][j] = c == '*'; }

    forn(i, n) forn(j, m) if (on[i][j]) {
        if (i != 0 && on[i - 1][j]) top[i][j] = top[i - 1][j] + 1;
        if (j != 0 && on[i][j - 1]) left[i][j] = left[i][j - 1] + 1;
    }

    dforn(i, n) dforn(j, m) if (on[i][j]) {
        if (i != n - 1 && on[i + 1][j]) bottom[i][j] = bottom[i + 1][j] + 1;
        if (j != m - 1 && on[i][j + 1]) right[i][j] = right[i][j + 1] + 1;
    }

    forn(i, n) forn(j, m) 
        if (on[i][j] && left[i][j] + right[i][j] > 0 && bottom[i][j] + top[i][j] > 0) {
            cnt[i - top[i][j]][j]++; 
            cnt[i][j - left[i][j]]++;
        }

    int ans = 0;
    forn(i, n) forn(j, m) 
        if (on[i][j] && left[i][j] > 0
            && left[i][j] == right[i][j] && right[i][j] == top[i][j] && bottom[i][j] > top[i][j] 
            && cnt[i - top[i][j]][j] == 1 && cnt[i][j - left[i][j]] == 1)
                ans++;

    cout << ans << endl;
	
	return 0;
}
