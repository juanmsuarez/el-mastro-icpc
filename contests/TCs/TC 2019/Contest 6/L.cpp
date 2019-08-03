#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;

int main(){
    int n; cin >> n;

    vi h(n), canth(n); canth[0] = 1;
    forsn(u, 1, n) {
        int p; cin >> p; p--;
        h[u] = h[p] + 1;  
        canth[h[u]]++;
    }

    int ans = 0;
    for (int c : canth) ans += c%2;
    cout << ans << endl;

    return 0;
}
