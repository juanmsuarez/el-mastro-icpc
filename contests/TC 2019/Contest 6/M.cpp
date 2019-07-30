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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 2*5e5, V = 2*N; 

struct SAT {
    //We have a vertex representing a var and other for his negation.
    //Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
    //V=max cant var, n=cant var
    vector<int> G[V*2];
    void addOr(int a, int b) { G[neg(a)].pb(b), G[neg(b)].pb(a); }
    void addImplication(int a, int b) { addOr(neg(a), b); }
    //idx[i]=index assigned in the dfs
    //lw[i]=lowest index(closer from the root) reachable from i
    int lw[V*2], idx[V*2], qidx;
    stack<int> q;
    int qcmp, cmp[V*2];
    //verdad[cmp[i]]=valor de la variable i
    bool verdad[V*2+1];

    int n;
    void init(int _n) { n = _n; }
    bool value(int x) { return verdad[cmp[x]]; }

    int neg(int x) { return x>=n? x-n : x+n;}
    void tjn(int v){
        lw[v]=idx[v]=++qidx;
        q.push(v), cmp[v]=-2;
        for(auto u : G[v]){
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
} sat;

int cantTerminals;

struct Trie {
    vi terminals;
    map<char,Trie*> ch;

    void insert(const string &s, int ind) {
        Trie *t = this;
        forn(i, si(s)) {
            if (t->ch.count(s[i]) == 0) t->ch[s[i]] = new Trie();
            t = t->ch[s[i]];
        }
        t->terminals.pb(ind);
    }

    void process(int pre = -1) {
        for (int terminal : terminals) {
            int pref = cantTerminals + terminal;
            if (pre != -1) {
                sat.addImplication(pre, pref); 
                sat.addImplication(pre, sat.neg(terminal));
            }
            sat.addImplication(terminal, pref);
            pre = pref;
        }

        for (auto [_, c] : ch) c->process(pre);
    }
} trie;

int main() {
	fastio;
	
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);

    int n; cin >> n;
    vector<string> v(n); for (string &s : v) cin >> s;

    cantTerminals = 2*n;
    sat.init(2*cantTerminals);
    forn(i, n) {
        string s = v[i];
        auto pos = s.find('?');

        if (pos == string::npos) {
            int terminal = i;
            trie.insert(s, terminal);

            sat.addOr(terminal, terminal);
        }
        else {
            int terminalZero = i; 
            s[pos] = '0';
            trie.insert(s, terminalZero);

            int terminalOne = n + i;
            s[pos] = '1';
            trie.insert(s, terminalOne);

            sat.addOr(terminalZero, terminalOne);
        }
    }

    trie.process();

    bool ans = sat.satisf();
    if (ans) {
        cout << "YES" << endl;
        forn(i, n) {
            string s = v[i];

            auto pos = s.find('?');
            if (pos != string::npos) {
                int terminalZero = i; 
                if (sat.value(terminalZero)) s[pos] = '0';
                else s[pos] = '1';
            }

            cout << s << endl;
        }
    }
    else cout << "NO" << endl;
	
	return 0;
}
