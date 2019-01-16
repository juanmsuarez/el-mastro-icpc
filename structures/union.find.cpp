// TODO: hacer mas eficiente
struct UnionFind{
	vector<int> f; // Arreglo que contiene los padres de cada nodo
	void init(int n){ f.clear(); f.insert(f.begin(), n, -1); }
	int comp(int x){ return f[x] == -1 ? x : f[x] = comp(f[x]); } // O(1)
	bool join(int i, int j){
		bool con = comp(i) == comp(j);
		if(!con) f[comp(i)] = comp(j);
		return con;
	}
};
