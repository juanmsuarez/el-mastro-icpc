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

const int MAXN = 1e5+10;
int n; tint fen[MAXN];
pii a[MAXN];
map<int, int> idx;

void add(int i) { // idx 1
	for (; i < MAXN; i += (i&-i))
		fen[i]++;
}

tint get(int i) { // idx 1
	tint res = 0;
	for (; i > 0; i -= (i&-i))
		res += fen[i];
	return res;
}

tint get(int i, int j) {
	return get(j) - get(i-1);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	cin >> n;
	forn(i, n)
		cin >> a[i].first >> a[i].second;

	sort(a, a+n);

	fill(fen, fen+MAXN, 0);
	idx.clear();
	
	// comprimo
	vi v;
	forn(i, n) v.pb(a[i].second);
	sort(v.begin(), v.end());
	int cnt = 1;
	forn(i, n) if (idx[v[i]] == 0) idx[v[i]] = cnt++;

	// cuento
	tint res = 0;
	forn(i, n) {
		int b = a[i].second;
		//cerr << b << "soy " << idx[b] << endl;
	
		res += get(idx[b]+1, n);	
		//cerr << "tengo " << get(idx[b]+1, n) << " mayores" << endl; 

		add(idx[b]);
		//cerr << "agrego " << idx[b] << endl;
	}

	cout << res << endl;

	return 0;
}
