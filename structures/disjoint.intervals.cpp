// Guarda intervalos como [first, second]
// En caso de colision, los une en un solo intervalo
bool operator <(const pii &a, const pii &b){ return a.first < b.first; }
struct disjoint_intervals {
	set<pii> segs;
	void insert(pii v){ // O(lg n)
		if(v.second - v.first == 0.0) return; // Cuidado!
		set<pii>::iterator it, at;
		at = it = segs.lower_bound(v);
		if(at != segs.begin() && (--at)->second >= v.first){
			v.first = at->first;
      --it;
    }
		for(; it!=segs.end() && it->first <= v.second; segs.erase(it++))
			v.second = max(v.second, it->second);
		segs.insert(v);
	}
};
