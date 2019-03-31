#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 1e4+10;

map<int,int> h;
int hasheamela(int a) {
    if (!h.count(a)) h[a] = si(h);
    return h[a];
}

vi adj[N];
int len[N];
bool seen[N];

ll acum(int u) {
    seen[u] = true;
    ll act = len[u];

    for (int v : adj[u])
        if (!seen[v])
            act += acum(v);

    return act;
}

int main() {
	fastio;
	
    int b, s; 
    
    while (cin >> b >> s) {
        h.clear();
        fill(seen, seen+b, false);
        forn(u, b) adj[u].clear();

        ll tot = 0;
        forn(i, b) {
            int bnum, blen, ps; cin >> bnum >> blen >> ps;
            bnum = hasheamela(bnum);

            len[bnum] = blen;
            while (ps--) {
                int p; cin >> p; p = hasheamela(p);
                adj[bnum].pb(p);
            }

            tot += blen;
        }

        while (s--) {
            int start; cin >> start; start = hasheamela(start);

            if (!seen[start]) tot -= acum(start);
        }

        cout << tot << endl;
    }
	
	return 0;
}
