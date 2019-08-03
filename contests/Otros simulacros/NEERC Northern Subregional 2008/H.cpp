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
    freopen("holes.in","r",stdin);
    freopen("holes.out","w",stdout);

    int h;
    cin >> h;
    if(!h)cout << 1 << endl;
    else if(h==1)cout << 0 << endl;
    else{
        if(h%2){
            cout << 4;
            h--;
        }
        while(h){
            cout << 8;
            h-=2;
        }
        cout << endl;
    }

    return 0;
}
