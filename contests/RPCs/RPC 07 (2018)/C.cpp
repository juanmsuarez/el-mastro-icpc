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

template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<ll> seq;
    set<ll>gcds;
    forn(i,n){
        ll a;
        cin >> a;
        vector<ll>nseq;
        for(ll p:seq){
            ll g = gcd<ll>(p,a);
            if(!si(nseq)||nseq.back()!=g){
                nseq.pb(g);
                gcds.insert(g);
            }
        }
        nseq.pb(a);
        gcds.insert(a);
        seq=nseq;
    }

    cout << si(gcds)<<endl;
    //for(auto a:gcds)cerr << a << endl;

    return 0;
}
