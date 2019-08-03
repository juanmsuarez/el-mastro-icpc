#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = (int) s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
using namespace std;

#define pb emplace_back
#define si(v) (int)((v).size())
using vi = vector<int>;

int main(){
    int n, k; cin >> n >> k;
    vi a(n); forn(i, n) cin >> a[i];

    vector<vi> ans(n);
    while (k > 0) {
        bool dif = false;
        while (!dif) {
            forn(i, n) 
                if (a[i] > 0) a[i]--, ans[i].pb(k);
                else dif = true;
        }
        k--;
    } 

    bool can = true;
    forn(i, n) if (a[i] != 0) can = false;
    if (can) {
        cout << "YES" << endl;
        for (vi &v : ans) forn(i, si(v)) cout << v[i] << " \n"[i==si(v)-1];
    }
    else cout << "NO" << endl;

    return 0;
}
