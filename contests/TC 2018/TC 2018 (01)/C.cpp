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

const int INF =1e6;

int main() {
    fastio;

    int n;
    cin >> n;
    vi ids(n);
    forn(i,n)cin >> ids[i];
    vi timeact(n,0),timedeath(n,INF),killer(n,-1);
    int psycho =0,victim=1;
    int maxtime=0;
    while(victim<n){
        if(timeact[psycho]==timedeath[psycho]||ids[psycho]<ids[victim]){
            if(killer[psycho]!=-1)psycho=killer[psycho];
            else{
                psycho = victim;
                victim++;
            }
        }
        else{
            timeact[psycho]++;
            maxtime=max(maxtime,timeact[psycho]);
            timedeath[victim]=timeact[psycho];
            killer[victim]=psycho;
            psycho=victim;
            victim++;
        }
    }
    cout << maxtime << endl;

    return 0;
}
