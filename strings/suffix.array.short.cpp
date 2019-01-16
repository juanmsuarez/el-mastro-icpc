const int MAXN = 2e5+10;
pii sf[MAXN];
bool comp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}
struct SuffixArray {
	//sa guarda los indices de los sufijos ordenados
    int sa[MAXN], r[MAXN];
    void init(const string &a) {
        int n = si(a);
        forn(i,n) r[i] = a[i];
        for(int m = 1; m < n; m <<= 1) {
			forn(i, n) sa[i]=i, sf[i] = mp(r[i], i+m<n? r[i+m]:-1);
            stable_sort(sa, sa+n, comp);
            r[sa[0]] = 0;
            forsn(i, 1, n) r[sa[i]]= sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i-1]];
        }
    }
} sa;

int main(){
    string in;
	while(cin >> in){
		sa.init(in, si(in));
		forn(i, si(in)) {
            forn(k, sa.sa[i]) cout << ' ';
            cout << in.substr(sa.sa[i]) << '\n';
        }
        cout << endl;
	}
	return 0;
}
