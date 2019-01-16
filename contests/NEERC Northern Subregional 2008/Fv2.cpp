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
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);

    int n; cin >> n;
    vector<ll> seq(n+1);
    forsn(i,1,n+1)cin>> seq[i];

    for(int i=2;i<n+1;i+=2){
        ll sum=0;
        for(int bit=(i&-i)>>1,j = i-(i&-i)+bit;j<i-1;bit>>=1,j+=bit){
            sum+=seq[j];
        }
        seq[i-1]=-sum;
    }
    string s="";
    forsn(i,1,n+1){
        cout <<s << seq[i];
        s=" ";
    }
    cout << endl;

    return 0;
}
