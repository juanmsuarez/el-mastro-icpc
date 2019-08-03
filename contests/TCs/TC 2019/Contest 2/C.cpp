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
    
    int n; cin >> n;
    vi a(n),b(n),c(n);
    forn(i,n) cin >> a[i];
    int m = n/2;
    b[m] = 0, c[m] = a[m];
    forn(i,m){
        int j = n-i-1, d = abs(a[i]-a[j]);
        if(d & 1) return cout << "NO\n", 0;
        c[i] = c[j] = (a[i]+a[j])/2;
        b[i] = d/2, b[j] = -d/2;
        if(a[i] < a[j]) swap(b[i],b[j]);
    }
    cout << "YES\n";
    forn(i,n) cout << b[i] << " \n"[i == n-1];
    forn(i,n) cout << c[i] << " \n"[i == n-1];
    return 0;
}
