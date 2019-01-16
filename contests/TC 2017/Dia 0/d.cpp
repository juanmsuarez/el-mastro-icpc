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

int res;

struct trie {
	typedef map<char,trie*> hijos;
	hijos child;
	bool final;
	int a, b;
	
	trie() {
		final = false;
		a=0;
		b=0;
	}
	
	void insert(const string &s, int team) {
		trie *now = this;
		int n = si(s);
		forn(i,n) {
			if (team == 0) now -> a++;
			else now -> b++;	
			// actualizar data del nodo
			
			if (!(now->child.count(s[i]))) 
				now->child[s[i]] = new trie();
				
			now = now->child[s[i]];	
		}
		
		if (team == 0) (now -> a)++;
		else (now -> b)++;	
		
		now->final = true; // o arco a '$'		
	}
	
	int solve(int p) {
		int act = 0;
		
		for(auto it : child) {
			trie* t = it.second;
			int nxt = t->solve(p+1);
			act += nxt;
			a -= nxt;
			b -= nxt;
		}
		
		act += min(a,b);
		res += p*min(a,b);
		
		return act;
	}
	
	void clear() {
		//for (hijos::iterator it = child.begin(); it != child.end(); it++) {
		for(auto it : child) {
			it.second->clear();					
		}
		child.clear();
	}
	
	bool find(const string& s) {
		trie *now = this;
		int n = si(s);
		forn(i,n) {
			if (!(now->child.count(s[i]))) return false;
			now = now->child[s[i]];			
		}
		return now->final;
	}
};

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	int n;
	while (cin >> n && n != -1) {
		res=0;
		trie* t = new trie();
		forn(i, n) {
			string s;
			cin >> s;
			t->insert(s, 0);
		}
		forn(i, n) {
			string s;
			cin >> s;
			t->insert(s,1);
		}
		t->solve(0);
		cout << res << endl;
	}
	
	return 0;
}
