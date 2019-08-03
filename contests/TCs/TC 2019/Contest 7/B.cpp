#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb emplace_back
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

int main(){
    fastio;

    int n; cin >> n;
    vi e[4];
    forn(i,4) e[i] = vi(n);
    forn(i,n) forn(j,4) cin >> e[j][i];
    int sz = n*n;
    vi a,c,ar(sz),b(sz);
    forn(i,n) forn(j,n) ar[n*i+j] = e[0][i] + e[1][j];
    forn(i,n) forn(j,n) b[n*i+j] = e[2][i] + e[3][j];
    sort(all(ar)); sort(all(b));
    forn(i,sz){
        if(i == 0) a.pb(ar[0]), c.pb(1);
        else {
            if(ar[i] == ar[i-1]) c[si(a)-1]++;
            else a.pb(ar[i]), c.pb(1);
        }
    }
    ll res = 0;
    for(int i = si(a)-1, j = 0; i >= 0 && j < sz; ){
        while(i >= 0 && a[i]+b[j] > 0) i--;
        if(i >= 0){
            if(a[i]+b[j] == 0) res += c[i], j++;
            else while(j < sz && a[i]+b[j] < 0) j++;
        }
    }
    cout << res << endl;
    return 0; 
}
