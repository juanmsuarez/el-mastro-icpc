#include <bits/stdc++.h>
using namespace std;

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

const int INF = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    vector<pii> inters;
    forn(i, n) {
        int x, w; cin >> x >> w;
        inters.pb(x-w, x+w);
    }

    sort(all(inters), [](pii a, pii b) {
        return a.snd < b.snd;
    });

    int maxr = -INF, cant = 0;
    for (auto inter : inters) {
        int l, r; tie(l, r) = inter;
        if (l >= maxr) maxr = r, cant++;
    }

    cout << cant << endl;

    return 0;
}
