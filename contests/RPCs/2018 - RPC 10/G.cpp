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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1e5+10;
#define rBOUND(x) (x<n? r[x] : 0)
string s; //input string, n=si(s)

int n;
pii sf[MAXN];
bool comp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}
struct SuffixArray {
	//sa guarda los indices de los sufijos ordenados
    int sa[MAXN], r[MAXN];
    int& operator[](int i) { return sa[i]; }
    void init(const string &a) {
        n = si(a);
        forn(i, n) r[i] = a[i];
        for(int m = 1; m < n; m <<= 1) {
			forn(i, n) sa[i]=i, sf[i] = mp(r[i], i+m<n? r[i+m]:-1);
            stable_sort(sa, sa+n, comp);
            r[sa[0]] = 0;
            forsn(i, 1, n) r[sa[i]]= sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i-1]];
        }
    }
} sa;


//Calculates the LCP between consecutives suffixes in the Suffix Array.
//LCP[i] is the length of the LCP between sa[i] and sa[i-1]
int LCP[MAXN], phi[MAXN], PLCP[MAXN];
void computeLCP(){//O(n)
	phi[sa[0]]=-1;
	forsn(i, 1, n) phi[sa[i]]=sa[i-1];
	int L=0;
	forn(i, n){
		if (phi[i]==-1) {PLCP[i]=0; continue;}
		while (s[i+L]==s[phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1, 0);
	}
	forn(i, n) LCP[i]=PLCP[sa[i]];
}

int main() {
	fastio;

    while (cin >> s) {
        string ord; cin >> ord;
        for (char &c : s) c = 'a'+ord.find(c);
        s += '$';
        sa.init(s);

        computeLCP();
        for (char &c : s) if (c != '$') c = ord[c-'a'];
        //print();

        int q; cin >> q;
        while (q--) {
            ll k; cin >> k;
            //cout << "BUSCO EL " << k << endl;

            string ans = "*"; int ap = 0;
            forsn(i, 1, n) {
                int len = n - sa[i] - 1, cant = len - LCP[i];

                //cerr << "mirando " << s.substr(sa[i], len) << " k " << k << " cnat " << cant << endl;

                if (cant >= k) {
                    ans = s.substr(sa[i], LCP[i]+k);
                    int j = i+1;
                    while (j < n && LCP[j] >= LCP[i]+k) j++;
                    ap = j-i;
                    break;
                }

                k -= cant;
            }

            cout << ans << endl << ap << endl;
        }
    }

	return 0;
}
