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
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pii>;
using ll = long long;

const int N = 1e6;
vi ord, v[N], marks[N];
bool on[N];
int n, ind[N];

int aStart(int i) {
    int m = si(v[i])/2, sum = 0;
    forn(j, m) sum += v[i][j];
    if (sum != 0) return -1;

    int j = 0, k = 0;
    while (j < m) {
        sum = 0;
        while (k < j + m && sum >= 0) sum += v[i][k++];
        if (sum >= 0) return j;
        j = k;
    } 
}

void markStarts(int i, int s) {
    int m = si(v[i])/2, sum = 0;

    marks[i] = vi(m);
    forsn(j, s, s+m) {
        marks[i][j%m] = sum == 0;
        sum += v[i][j];
    }
}

pii getMax() {
    int sum = 0;
    dforn(k, n) {
        int i = ord[k], &j = ind[i], m = si(marks[i]);
        if (marks[i].empty()) continue;
        if (marks[i][m-1-j]) on[i] = true, sum++;
        else if (on[i]) on[i] = false, sum--;
        j = (j+1)%m;
    }

    pii ans = {0, 0};
    dforn(k, n) {
        int i = ord[k], &j = ind[i], m = si(marks[i]);

        if (!marks[i].empty()) {
            if (marks[i][m-1-j]) on[i] = true, sum++;
            else if (on[i]) on[i] = false, sum--;
            j = (j+1)%m; 
        }

        ans = max(ans, {sum, -k});
    }

    return ans;
}

int main() {
	fastio;
	
    cin >> n;
    forn(i, n) {
        char c; int t; cin >> c >> t;
        v[t-1].pb(c == 's' ? 1 : -1);
        ord.pb(t-1);
    }

    forn(i, N)
        if (!v[i].empty()) {
            int m = si(v[i]);
            forn(j, m) v[i].pb(v[i][j]);

            int s = aStart(i);
            if (s != -1) markStarts(i, s);
        }

    pii ans = getMax();
    cout << -ans.snd+1 << ' ' << ans.fst << endl;
	
    return 0;
}
