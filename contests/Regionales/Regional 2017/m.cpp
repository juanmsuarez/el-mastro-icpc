#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXSZ = 5e5+10, MOD = 1e9+7;

tint pot365[MAXSZ];
pair<int, int> sf[MAXSZ];
bool comp(int lhs, int rhs) {return sf[lhs] < sf[rhs];}
struct SuffixArray {
	//sa guarda los indices de los sufijos ordenados
    int sa[MAXSZ], r[MAXSZ];
    void init(vi a) {
        int n = si(a);

        forn(i, n) r[i] = a[i];
        for (int m = 1; m < n; m <<= 1) {
			forn(i, n) sa[i]=i, sf[i] = make_pair(r[i], i+m<n? r[i+m]:-1);
            stable_sort(sa, sa+n, comp);
            r[sa[0]] = 0;
            forsn(i, 1, n) r[sa[i]]= sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i-1]];
        }
    }
} sa;

int main() {
    fastio;

    pot365[0] = 1; 
    forsn(i, 1, 4e5+1) pot365[i] = pot365[i-1]*365%MOD;

    int n, tot = 0;
    cin >> n;
    
    vi a;

    while (n--) {
        int k;
        cin >> k;
        tot += k;
        
        forn(_, k) {
            int v;
            cin >> v;
            a.pb(v); 
        }

        a.pb(301);
    }

    sa.init(a);

    set<pii> s;
    forn(i, si(a)) {
        //cerr << a[i] << " orden " << sa.sa[i] << endl;
        if (i == 0 || a[i-1] == 301)
            s.insert(mp(sa.r[i], i));
    }

    tint ans = 0;
    while (!s.empty()) {
        int i = s.begin()->second;
        s.erase(s.begin());

        //cerr << a[i] << ' ' << tot << endl;
        ans = (ans + a[i]*pot365[tot--]%MOD)%MOD;

        if (a[i+1] != 301) s.insert(mp(sa.r[i+1], i+1));
    }

    cout << ans << endl;

    return 0;
}
