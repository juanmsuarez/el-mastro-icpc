const int MAXN = 1e5+10, INF = 1e8;

//Para non-increasing, cambiar comparaciones y revisar busq binaria
//Given an array, paint it in the least number of colors so that each color turns to a non-increasing subsequence.
//Solution:Min number of colors=Length of the longest increasing subsequence
int N, a[MAXN];//secuencia y su longitud
pii d[MAXN+1];//d[i]=ultimo valor de la subsecuencia de tamanio i
int p[MAXN];//padres
vector<int> R;//respuesta
void rec(int i){
	if(i==-1) return;
	R.pb(a[i]);
	rec(p[i]);
}
int lis(){//O(nlogn)
	d[0] = pii(-INF, -1); forn(i, N) d[i+1]=pii(INF, -1);
	forn(i, N){
		int j = upper_bound(d, d+N+1, pii(a[i], INF))-d;
		if (d[j-1].first < a[i]&&a[i] < d[j].first){ // check < por <= en d[j-1]
			p[i]=d[j-1].second;
			d[j] = pii(a[i], i);
		}
	}
	R.clear();
	dforsn(i, 0, N+1) if(d[i].first!=INF){
		rec(d[i].second);//reconstruir
		reverse(R.begin(), R.end());
		return i;//longitud
	}
	return 0;
}

int main(){
	while(cin >> N){
		forn(i, N) cin >> a[i];
		lis();
		for (auto it :  R) cout << it << ' '; cout << endl;
	}
	return 0;
}
