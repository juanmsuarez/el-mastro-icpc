struct state {
	int len, link;
	map<char,int> next;
	state() { }
};
const int MAXLEN = 1e5+10;
state st[MAXLEN*2];
int sz, last;
void sa_init() {
	forn(i,sz) st[i].next.clear();
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
}
// Es un DAG de una sola fuente y una sola hoja
// cantidad de endpos = cantidad de apariciones = cantidad de caminos de la clase al nodo terminal
// cantidad de miembros de la clase = st[v].len-st[st[v].link].len (v>0) = caminos del inicio a la clase
// El arbol de los suffix links es el suffix tree de la cadena invertida. La string de la arista link(v)->v son los caracteres que difieren
void sa_extend (char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	// en cur agregamos la posicion que estamos extendiendo
	// podria agregar tambien un identificador de las cadenas a las cuales pertenece (si hay varias)
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link) // modificar esta linea para hacer separadores unicos entre varias cadenas (c=='$')
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
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next.count(c) && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
