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

const int A = 26;

struct state {
	int len, link;
	int next[A];
    state() {
        forn(c, A) next[c] = -1;
    }
};
const int N = 2e5;
state st[N*2];
int sz, last;
void sa_init() {
	forn(i,sz) forn(c, A )st[i].next[c] = -1;
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
}
// Es un DAG de una sola fuente y una sola hoja
// cantidad de endpos = cantidad de apariciones = cantidad de caminos de la clase al nodo terminal
// cantidad de miembros de la clase = st[v].len-st[st[v].link].len (v>0) = caminos del inicio a la clase
// El arbol de los suffix links es el suffix tree de la cadena invertida. La string de la arista link(v)->v son los caracteres que difieren
void sa_extend (char _c) {
    int c = _c - 'A';

	int cur = sz++;
	st[cur].len = st[last].len + 1;
	// en cur agregamos la posicion que estamos extendiendo
	// podria agregar tambien un identificador de las cadenas a las cuales pertenece (si hay varias)
	int p;
	for (p=last; p!=-1 && st[p].next[c] == -1; p=st[p].link) // modificar esta linea para hacer separadores unicos entre varias cadenas (c=='$')
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			forn(c, A) st[clone].next[c] = st[q].next[c];
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c] != -1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

int match(string &t) {
    int used = 1;

    int cur = 0;
    for (char _c : t) {
        int c = _c - 'A';
        if (st[cur].next[c] == -1) {
            cur = 0, used++;
            if (st[cur].next[c] == -1) return -1;
        }

        cur = st[cur].next[c];
    }

    return used;
}

int main() {
	fastio;
	
    sa_init();

    string s; cin >> s;
    for (char c : s) sa_extend(c);

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        cout << match(t) << endl;
    }
	
	return 0;
}
