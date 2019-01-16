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

    int d;
    cin >> d;

    vector<tint> seq =vector<tint>();
    int prev;
    cin >> prev;
    int dir=-1;
    int act;
    forn(i,d-1){
        cin >> act;
        if(dir*act<dir*prev){
            dir*=-1;
            seq.pb(prev);
        }
        prev=act;
    }
    seq.pb(prev);

    
    tint money=100;
    
    for(int i=0;i<si(seq)-1;i+=2){
        tint shares=0;
        shares+=min(100000LL,money/seq[i]);
        money-=seq[i]*shares;
        money+=shares*seq[i+1];
    }
    cout << money << endl;
    
    return 0;
}
