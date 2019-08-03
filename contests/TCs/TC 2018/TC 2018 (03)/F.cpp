#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) dforsn(i, 0, n)
#define forn(i,n) forsn(i, 0, n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef long long int ll;
typedef vector<int> vi;

const int MAXC = 30;
vector<pair<char,int>> nxt[MAXC];

int main() {
    fastio;

    int nc;
    cin >> nc;
    while (nc--) {
        forn(c, MAXC) nxt[c].clear();

        string in, s; cin >> in;
        forn(i, si(in)) {
            char c = in[i]; int cant = 0;
            while (i+1 < si(in) && in[i+1] >= '0' && in[i+1] <= '9') {
                cant = cant*10 + in[i+1] - '0';
                i++;
            } 
            if (cant == 0) cant = 1;

            forn(_, cant) s += c;
        }
        //cerr << s << endl;

        int n = si(s);
        string sorted = s; sort(all(sorted));

        pair<char,int> act; int ind = 0;
        forn(i, n) {
            if (s[i] == '.') act = {sorted[i], ind};
            else nxt[s[i]-'A'].pb(sorted[i], ind);

            if (i+1 < n && sorted[i+1] == sorted[i]) ind++;
            else ind = 0;
        }

        string ans;
        while (act.fst != '.') {
            ans += act.fst;
            act = nxt[act.fst-'A'][act.snd];
        }
        ans += '.';
        cout << ans << endl;
    } 

    return 0;
}
