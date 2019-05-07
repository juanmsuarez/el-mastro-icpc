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

const int N = 1e6;

int n, par[N], partemp[N], len[N];
char ch[N];

pii sf[N];
bool comp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}
//sa guarda los indices de los sufijos ordenados
int sa[N], r[N];
void init() {
    forn(i, n) r[i] = ch[i], partemp[i] = par[i];
    for(int m = 1; m < n; m <<= 1) {
        dforn(i, n) {
            sa[i]=i; 
            sf[i] = mp(r[i], m < len[i]? r[partemp[i]]:-1); 
            partemp[i] = partemp[partemp[i]];
        }
        stable_sort(sa, sa+n, comp);
        r[sa[0]] = 0;
        forsn(i, 1, n) r[sa[i]]= sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i-1]];
    }
}

int compare(int i, string &p) {
    //cerr << "comp " << i << " con " << p << endl;
    int act = i;
    forn(k, si(p)) {
        if (act == -1) return -1;
        //cerr << ch[act] << ' ' << p[k] << endl;
        if (ch[act] < p[k]) return -1;
        else if (ch[act] > p[k]) return 1;
        act = par[act];
    } 
    return 0;
}

//returns (lowerbound, upperbound) of the search
pii stringMatching(string &p){ //O(si(p)lgn)
	int lo=0, hi=n-1, mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res=compare(sa[mid], p);
        //cerr << sa[lo] << ' ' << sa[hi] << ' ' << res << endl;
		if(res>=0) hi=mid;
		else lo=mid+1;
	}
	if(compare(sa[lo], p)!=0) return pii(-1, -1);
	pii ans; ans.first=lo;
	lo=0, hi=n-1;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res=compare(sa[mid], p);
		if(res>0) hi=mid;
		else lo=mid+1;
	}
	if(compare(sa[hi], p)!=0) hi--;
    hi++;
	ans.second=hi;
	return ans;
}

int main() {
	fastio;
	
    int k; cin >> n >> k;
    forn(i, n) {
        cin >> ch[i] >> par[i];
        par[i]--;
    }

    forn(i, n) len[i] = par[i] >= 0 ? len[par[i]]+1 : 1;

    init();

    while (k--) {
        string s; cin >> s;
        int lo, hi; tie(lo, hi) = stringMatching(s);        
        cout << hi-lo << endl;
    }
	
	return 0;
}
