#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a <<endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i=int(s);i<(int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=(int)s;i--)
#define dforn(i,n) dforsn(i,0,n)

#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second 
#define fst first
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(){
    fastio;

    int t; cin >> t;
    while (t--) {
        double n; cin >> n;
        double res = (1 + 1./2 - 1/n - 1/(n+1))/2 + (n+1)/(n*(n+2));
        cout << fixed << setprecision(11) << res << endl;
    }

    return 0;
}
