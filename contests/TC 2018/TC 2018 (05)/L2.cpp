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
int adj[MAXN];
int s[MAXN];
int n;
bool can(int k) {
    s[1]=0;
    dforsn(i,1,n+1){
        if(1+s[i]!=k) s[adj[i]]+=1+s[i];
        if(i!=1)s[i]=0;
    }
    return 1+s[1]==k;
}

int main() {
    scanf("%d", &n);
    forsn(i, 1, n) {
        int v; 
        scanf("%d", &v);
        adj[i+1]=v;
    }

    vi ans;
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
