struct trie {
    int p = 0, w = 0;
    map<char,trie*> c;
    trie(){}
    void add(const string &s){
        trie *x = this;
        forn(i,si(s)){
            if(!x->c.count(s[i])) x->c[s[i]] = new trie();
            x = x->c[s[i]];
            x->p++;
        }
        x->w++;
    }
    int find(const string &s){
        trie *x = this;
        forn(i,si(s)){
            if(x->c.count(s[i])) x = x->c[s[i]];
            else return 0;
        }
        return x->w;
    }
    void erase(const string &s){
        trie *x = this, *y;
        forn(i,si(s)){
            if(x->c.count(s[i])) y = x->c[s[i]], y->p--;
            else return;
            if(!y->p){
                x->c.erase(s[i]);
                return;
            }
            x = y;
        }
        x->w--;
    }
	void print(string tab = "") {
		for(auto &i : c) {
			cerr << tab << i.fst << endl;
			i.snd->print(tab + "--");			
		}
	}
};
