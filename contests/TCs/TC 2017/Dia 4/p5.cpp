#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10, INF=1<<30;
int lazy[2*MAXN], mn[2*MAXN];

struct node {
    int ll, rr, id;

    node(int L, int R, int X) {
        ll=L, rr=R, id=X;
        lazy_update();
    }

    node left() {
        return node(ll, (ll+rr)/2, id*2);
    }
    node right() {
        return node((ll+rr)/2+1, rr, id*2+1);
    }
    
    void lazy_update() {
        if (lazy[id]==-1) return;
        if (ll!=rr) lazy[2*id]=lazy[2*id+1]=lazy[id];
        mn[id]=min(mn[id],lazy[id]); 
        lazy[id]=-1;
    }

    void assign_range(int L, int R, int X) {
        if (ll>R || rr<L) return;
        if (ll>=L && rr<=R) {
            lazy[id]=X;
            lazy_update();
            return;
        }
        left().assign_range(L, R, X);
        right().assign_range(L, R, X);
        mn[id]=min(mn[id*2], mn[id*2+1]);
    }

    int min_range(int L, int R) {
        if (ll>R || rr<L) return INF;
        if (ll>=L && rr<=R) return mn[id];
        int mn1=left().min_range(L, R);
        int mn2=right().min_range(L, R);
        return min(mn1, mn2);
    }
};

typedef pair<int,int> pii;
#define forn(i,n) for(int i = 0; i < (int)(n); i++)

int main() {
    //freopen("in.txt","r",stdin);
    
    int nc;
    cin >> nc;
    while (nc--) {
		int n,m;
		cin >> n >> m;
		
		fill(mn, mn+2*MAXN, INF);
		fill(lazy,lazy+2*MAXN, -1);
		
		node root (1, n, 1);
		root.assign_range(1,1,0);
		forn(i, m) {		
			int a, b;
			cin >> a >> b;
			int r = root.min_range(a,b);
			//cout << " min en " << s[i].first << ' '  <<s[i].second << ' ' << a << endl;
			if (r < INF) root.assign_range(b,b,r+1);
		}
		cout << root.min_range(n, n) << endl;
		if (nc) cout << endl;
	}
    
    return 0; 
}
