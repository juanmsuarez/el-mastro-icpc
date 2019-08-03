#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAX = 2e4+10;
//We have a vertex representing a var and other for his negation.
//Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
//MAX=max cant var, n=cant var
#define addor(a, b) (G[neg(a)].pb(b), G[neg(b)].pb(a)) 
vector<int> G[MAX*2];
//idx[i]=index assigned in the dfs
//lw[i]=lowest index(closer from the root) reachable from i
int n, lw[MAX*2], idx[MAX*2], qidx;
stack<int> q;
int qcmp, cmp[MAX*2];
//verdad[cmp[i]]=valor de la variable i
bool verdad[MAX*2+1];

int neg(int x) { return x>=n? x-n : x+n;}
void tjn(int v){
	lw[v]=idx[v]=++qidx;
	q.push(v), cmp[v]=-2;
	for(int u : G[v]){
		if(!idx[u] || cmp[u]==-2){
			if(!idx[u]) tjn(u);
			lw[v]=min(lw[v], lw[u]);
		}
	}
	if(lw[v]==idx[v]){
		int x;
		do{x=q.top(); q.pop(); cmp[x]=qcmp;}while(x!=v);
		verdad[qcmp]=(cmp[neg(v)]<0);
		qcmp++;
	}
}
//remember to CLEAR G!!!
bool satisf(){//O(n)
    fill(idx, idx+2*MAX, 0); qidx = 0;
    fill(cmp, cmp+2*MAX, -1); qcmp = 0;
	forn(i, n){
		if(!idx[i]) tjn(i);
		if(!idx[neg(i)]) tjn(neg(i));
	}
	forn(i, n) if(cmp[i]==cmp[neg(i)]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int m;
	while (cin >> n >> m) {
		forn(u,2*n)
			G[u].clear();
		forn(i, m) {
			char ca, cb;
			int a, b;
			cin >> ca >> a >> cb >> b;
			a--; b--;
			int t1 = ca == '+' ? a : neg(a),
				t2 = cb == '+' ? b : neg(b);
			addor(t1, t2);
		}
		
		cout << satisf() << endl;
	}

	return 0;
}
