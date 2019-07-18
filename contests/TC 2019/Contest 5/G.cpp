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

const int INF = 1e9;
const string VOWELS = "aeiou";
bool isVowel(char c) { return VOWELS.find(tolower(c)) != string::npos; }

int main() {
	fastio;
	
    string s; cin >> s;

    int n = si(s); 
    vi v(n); forn(i, n) v[i] = isVowel(s[i]) ? -1 : 2;

    vector<pii> pref(n+1);
    forsn(i, 1, n+1) pref[i] = {pref[i-1].fst + v[i-1], i};
    sort(all(pref));

    int mnind = INF, mxlen = 0, rep = 0;
    for (auto [sum, ind] : pref) {
        if (mnind != INF) {
            int len = ind - mnind;
            if (len > mxlen) mxlen = len, rep = 1;
            else if (len == mxlen) rep++;
        } 

        mnind = min(mnind, ind);
    }
   
    if (mxlen == 0) cout << "No solution" << endl;
    else cout << mxlen << ' ' << rep << endl;
	
	return 0;
}
