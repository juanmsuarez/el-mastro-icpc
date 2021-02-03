struct Trie {
    int u = 0, ws = 0;
    map<char, Trie*> c;
    Trie() {}
    void add(const string &s) {
        Trie *x = this;
        forn(i, si(s)){
            if(!x->c.count(s[i])) x->c[s[i]] = new Trie();
            x = x->c[s[i]];
            x->u++;
        }
        x->ws++;
    }
    int find(const string &s) {
        Trie *x = this;
        forn(i, si(s)){
            if (x->c.count(s[i])) x = x->c[s[i]];
            else return 0;
        }
        return x->ws;
    }
    void erase(const string &s) {
        Trie *x = this, *y;
        forn(i, si(s)){
            if (x->c.count(s[i])) y = x->c[s[i]], y->u--;
            else return;
            if (!y->u){
                x->c.erase(s[i]);
                return;
            }
            x = y;
        }
        x->ws--;
    }
	void print(string tab = "") {
		for (auto &i : c) {
			cerr << tab << i.fst << endl;
			i.snd->print(tab + "--");			
		}
	}
};
