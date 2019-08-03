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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 3e6+10;
vi adj[MAXN];
int s[MAXN];

int n;

void dfs(int u,int prev=-1){
    s[u]=1;
    for(auto v:adj[u]){
        if(v!=prev){
            dfs(v,u);
            s[u]+=s[v];
        }
    }
}

bool can(int k){
    int cant=0;
    forn(i,n)if(!(s[i]%k))cant++;
    return cant==n/k;
}

int main() {
    scanf("%d", &n);
    
    forsn(u, 1, n) {
        int v; 
        scanf("%d", &v);
        v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi ans;
    dfs(0);
    for (int k = 1; k*k <= n; k++) {
        if (n%k == 0){
            if (can(k))ans.pb(n/k);
            if (k*k != n && can(n/k)) ans.pb(k);
        }
    }

    sort(all(ans));
    forn(i, si(ans)) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
