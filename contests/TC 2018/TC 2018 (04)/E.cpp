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

const double EPS = 1e-7;
const int MAXN=1000+10;
double memo[MAXN];
int ans[MAXN];

int main() {
    fastio;

    int k;
    cin >> k;
    int q;
    cin >> q;
    vector<pair<double,int>> qs(q);
    forn(i,q) {
        cin >> qs[i].first;
        qs[i].second = i;
    }
    sort(all(qs));

    int x = 0;
    fill(memo,memo+MAXN,0);
    memo[0]=1;
    forn(i, q) {
        double p = qs[i].first;
        int ind = qs[i].second;

        while(memo[k]*2000.0 < p - EPS) {
            x++;
            dforsn(j,1,k+1)memo[j]=(j*memo[j]+(k-j+1)*memo[j-1])/k;
            memo[0]=0;
        }
        ans[ind] = x;
    }

    forn(i, q) cout << ans[i] << endl;

    return 0;
}
