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

ll shft=1e9;

int main() {
    fastio;

    int t;
    cin >> t;
    while(t--){
        ll d, n;
        cin >> d >> n;

        vi col(d,0), fil(d,0);
        vector<vi> corner(d,vi(d,0));

        D(n);
        forn(i,n){
            ll x,y;
            cin >> x >> y;
            x+=shft;
            y+=shft;
            //cerr << x%d << " " << y%d << endl;
            fil[int(x%d)]++;
            col[int(y%d)]++;
            corner[int(x%d)][int(y%d)]++;
        }
        int res=fil[0]+col[0]-corner[0][0];
        //forn(i,d)cerr << fil[i] << " ";
        //cerr << endl;
        //forn(i,d)cerr << col[i] << " ";
        //cerr << endl;
        forn(i,d){
            forn(j,d){
                res=min(res,fil[i]+col[j]-corner[i][j]);
            }
        }
        cout << res << endl;
    }


    return 0;
}
