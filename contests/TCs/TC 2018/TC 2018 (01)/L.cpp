include <bits/stdc++.h>
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

const int MAXN = 20;
int k, n;
double p[MAXN], ans[MAXN], memo[1<<MAXN], sump[1<<MAXN];

double dp(int m) {
    if (m == 0) return 1;

    double &res = memo[m];
    if (res != -1) return res;
    res = 0;

    forn(i, n)
        if (m & (1<<i)) 
            res += dp(m ^ (1<<i)) * p[i] / sump[((1<<n)-1) - (m ^ (1<<i))];

    return res;
}

int main() {
    fastio;

    cin >> n >> k;
    int N = n;
    vi zeros(1, 0);
    forn(i, n) {
        cin >> p[i];
        if (p[i] == 0) {
            zeros.back()++;
            i--; 
            n--;
        }
        else zeros.pb(zeros.back());
    }
    k = min(n, k);

    fill(memo, memo+(1<<n), -1);
    forn(m, 1<<n) forn(i, n) if (m & (1<<i)) sump[m] += p[i]; 

    forn(m, 1<<n)
        if (__builtin_popcount(m) == k)
            forn(i, n) 
                if (m & (1<<i)) 
                    ans[i+zeros[i]] += dp(m); 

    cout << fixed << setprecision(6);
    forn(i, N) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
