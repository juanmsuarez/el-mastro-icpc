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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAX = 55;

//We have a vertex representing a var and other for his negation.
//Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
//MAX=max cant var, n=cant var
#define addor(a, b) (G[neg(a)].pb(b), G[neg(b)].pb(a)) 
vector<int> G[MAX*2];
//idx[i]=index assigned in the dfs
//lw[i]=lowest index(closer from the root) reachable from i
int lw[MAX*2], idx[MAX*2], qidx;
stack<int> q;
int n, qcmp, cmp[MAX*2];
//verdad[cmp[i]]=valor de la variable i
bool verdad[MAX*2+1];

int neg(int x) { return x>=n? x-n : x+n;}
void tjn(int v){
	lw[v]=idx[v]=++qidx;
	q.push(v), cmp[v]=-2;
	for (auto u : G[v]){
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
	memset(idx, 0, sizeof(idx)), qidx=0;
	memset(cmp, -1, sizeof(cmp)), qcmp=0;
	forn(i, n){
		if(!idx[i]) tjn(i);
		if(!idx[neg(i)]) tjn(neg(i));
	}
	forn(i, n) if(cmp[i]==cmp[neg(i)]) return false;
	return true;
}

vi basicG[MAX*2];

inline int getCard(int c, int p) {
    return p*26+c;
}

int main() {
    fastio;

    n = 52;
    int N;
    cin >> N;
    forn(i, N) {
        char a, b; int p, r;
        cin >> a >> b >> p >> r;
        p--;
        int na = getCard(a-'A', p), nb = getCard(b-'A', p);

        if (r == 0) {
            addor(neg(na), neg(na));
            addor(neg(nb), neg(nb));
        }          
        else if (r == 1) {
            addor(na, nb);
            addor(neg(na), neg(nb));
        }
        else {
            addor(na, na);
            addor(nb, nb);
        }
    }

    forn(i, 2*MAX) basicG[i] = G[i];

    int ans = 0;

    forn(a, 26)
        forsn(b, a+1, 26)
            forsn(c, b+1, 26) {
                forn(i, 2*MAX) G[i] = basicG[i];

                forn(card, 26) {
                   int c1 = getCard(card, 0), c2 = getCard(card, 1);
                   if (card == a || card == b || card == c) {
                       addor(neg(c1), neg(c1));
                       addor(neg(c2), neg(c2));
                   }
                   else {
                      addor(c1, c2); 
                      addor(neg(c1), neg(c2));
                   }
                }

                if (satisf()) ans++;

                /*
                if (satisf() && a == 0) {
                    cerr << "da " << a << ' ' << b << ' ' << c << endl;
                    forn(i, 2*MAX) {
                        if (G[i].empty()) continue;
                        cerr << i << ": ";
                        for (int v : G[i]) cerr << v << ' ';
                        cerr << endl;
                    }
                }
                */
            } 

    cout << ans << endl;

    return 0;
}
