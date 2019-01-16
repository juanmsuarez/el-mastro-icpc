// TODO: actualizar para las macros nuevas
struct trie {
	typedef map<char,trie*> hijos;
	hijos child;
	bool final;
	
	trie() {
		final = false;
	}
	
	void insert(const string &s) {
		trie *now = this;
		int n = si(s);
		forn(i,n) {
			// actualizar data del nodo
			
			if (!(now->child.count(s[i]))) 
				now->child[s[i]] = new trie();
				
			now = now->child[s[i]];			
		}
		now->final = true; // o arco a '$'		
	}
	
	void clear() {
		//for (hijos::iterator it = child.begin(); it != child.end(); it++) {
		forall(it,child) {
			it->second->clear();					
		}
		child.clear();
	}
	
	void print(string tab = "") {
		forall(it,child) {
			cerr << tab << it->first << endl;
			it->second->print(tab + "--");			
		}
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
