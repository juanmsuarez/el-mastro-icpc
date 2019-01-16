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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int main() {
    fastio;

    int n;
    double g;
    cin >> n >> g;
    vector<pair<double,double>>seq(n);
    
    forn(i,n)cin >> seq[i].first >> seq[i].second;

    double v2=0;
    vector<double>res;
    dforsn(i,0,n){
        v2+=2.0*g*cos(seq[i].second*acos(-1)/180)*seq[i].first;
        //DBG(v2);
        res.pb(sqrt(v2));
    }

    dforsn(i,0,si(res))
        cout << fixed << setprecision(7) << res[i] << endl;
    return 0;
}
