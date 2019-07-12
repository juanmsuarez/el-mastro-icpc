#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 2e3;

vi g[N];
int l[N];

bool homo(int n){
    for(int v : g[n]){
        if(l[v]){
            if(l[v] == l[n]) return 1;
        } else {
            l[v] = l[n] == 1 ? 2 : 1;
            if(homo(v)) return 1;
        }
    }
    return 0;
}

int main() {
    int t; cin >> t;
    forn(_,t){
        int n,m; cin >> n >> m;
        forn(i,n) l[i] = 0, g[i].clear();

        forn(i,m){
            int x,y; cin >> x >> y; x--,y--;
            g[x].pb(y), g[y].pb(x);
        }    
        cout << "Scenario #" << _+1 << ":\n";
        bool ok = 1;
        forn(i,n) if(!l[i]){ 
            l[i] = 1;
            if(homo(i)){ ok = 0; break; }
        }
        cout << (ok ? "No s" : "S") << "uspicious bugs found!\n";
    }

    return 0;
}
