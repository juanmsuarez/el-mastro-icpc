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

int main() {
    fastio;

    ll n;
    cin >> n;
    ll sum=0,res=0;
    vector<ll> seq(n);
    forn(i,n)cin >> seq[i];
    sort(all(seq),greater<ll>());

    ll cant = 1;
    while(cant<=n){
          forsn(i,cant/4ll,cant){
                sum+=seq[i];
          }
          res+=sum;
          D(res);
          cant*=4ll;
    }
    cout << res << endl;

    return 0;
}
