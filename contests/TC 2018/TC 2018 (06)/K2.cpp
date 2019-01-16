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
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int INF = 1e9;

struct trie {
	typedef map<char,trie*> hijos;
	hijos child;
	bool final;
    int ind;
	
	trie() {
		final = true;
        ind = INF;
	}
	
	void insert(const string &s, int ind) {
		trie *now = this;
		int n = si(s);
		forn(i,n) {
			// actualizar data del nodo
			
			if (!(now->child.count(s[i]))) 
				now->child[s[i]] = new trie();
				
			now = now->child[s[i]];			
		}
		now->final = true; // o arco a '$'		
        now->ind = min(now->ind, ind);
	}
	
	void print(string tab = "") {
        for (auto p : child) {
			//cerr << tab << p.first << endl;
			p.second->print(tab + "--");			
		}
	}
	
	int find(const string& s) {
		trie *now = this;
		int n = si(s);
		forn(i,n) {
			if (!(now->child.count(s[i]))) return INF;
			now = now->child[s[i]];			
		}
        //cerr << "buscando " << s << " encontre " << now->ind << endl;
        return now->ind;
	}
};

const int MAXL = 1000+10;

int main() {
    fastio;

    trie t1, t2;
    string s;
    int m;
    cin >> s >> m;
    int n = si(s);

    forn(i, n) {
        string w;
        forsn(j, i, min(n, i+MAXL)) {
            w += s[j];

            //cerr << "inserto " << w << " con " << i << ' ' << j << endl;
        }
            t1.insert(w, j);
            t2.insert(w, -i);
    }

    int ans = 0;
    forn(_, m) {
        string w, lw, rw;
        cin >> w;
        rw = w;

        //cerr << "MIRANDO " << w << endl;
        
        bool can = false;
        forn(i, si(w)-1) {
            lw += w[i];
            rw.erase(rw.begin());
            
            int l = t1.find(lw), r = -t2.find(rw);
            //cerr << "para " << lw << ' ' << rw << " encontre " << l << ' ' << r << endl;

            if (l < r) {
                can = true;
                break;
            }
        }

        ans += can;
    }
    cout << ans << endl;

    return 0;
}
