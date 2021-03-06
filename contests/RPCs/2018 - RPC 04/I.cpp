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
    while (cin >> n && n != 0) {
        vi a(n); 
        forn(i, n) cin >> a[i];

        sort(all(a));
        
        cout << fixed << setprecision(1);
        if (n%2 == 1) cout << double(a[n/2]) << endl;
        else cout << double(a[n/2]+a[n/2-1])/2 << endl;
    }

    return 0;
}
