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

const double EPS=.5;

int main() {
    fastio;

    int m,n;
    cin >> m >> n;

    vector<double> seqA(m), seqB(n);
    forn(i,m)cin >> seqA[i];
    forn(i,n)cin >> seqB[i];

    int res=0;
    vi ans;
    forn(i,n){
        double v = double(seqB[i])/double(seqA[0]);
        int indB = i+1;
        bool match=true;
        int scnd=-1;
        for(int indA=1;match&&indA<m;indA++){
            while(indB<n && v*seqA[indA]>seqB[indB]+EPS)indB++;
            match = indB<n && abs(v*seqA[indA]-seqB[indB])<=EPS;
            if(match&&scnd==-1)scnd=(int)seqB[indB];
            indB++;
        }
        if(match){
            res++;
            ans.pb(scnd-seqB[i]);
        }
    }
    
    cout << res << endl;
    forn(i,si(ans))cout<< (i?" ":"") << ans[i];
    cout << endl;

    return 0;
}
