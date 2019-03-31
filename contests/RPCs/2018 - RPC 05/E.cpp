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
    while (cin >> n){
        tint a[n];
        forn(i,n) cin >> a[i];
        tint r = 0;
        forn(i,n){
            tint m = INT_MIN, s = 0;
            for(int j = i; j < n; j++){
                s += a[j];
                if(s > m) m = s;
                r ^= m;
                if(s < 0) s = 0;
            }
        }
        cout << r << endl;
    }
    return 0;
}
