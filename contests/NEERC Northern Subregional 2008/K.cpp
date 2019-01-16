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
typedef long long int ll;

int main() {
    fastio;
    freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);

    int n,m;
    cin >> n >> m;
    priority_queue<ll,vector<ll>,greater<ll>> have;
    forn(i,n){
        ll a;
        cin >> a;
        have.push(a);
    }
    ll minact =1;
    vector<ll> res;

    while(m--){
        while(!have.empty() && have.top()<=minact){
            minact+=have.top();
            have.pop();
        }
        res.pb(minact);
        minact*=2ll;
    }

    string s="";
    for(auto a:res){
        cout << s << a;
        s=" ";
    }
    cout << endl;

    return 0;
}
