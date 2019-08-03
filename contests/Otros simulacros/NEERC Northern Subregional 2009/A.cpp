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

int main() {
	fastio;
	
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);

    string s; 
    while (cin >> s) {
        forn(i, si(s)) 
            if (s[i] == '(') s.insert(s.begin()+i+1, ')'), i++;
            else if (s[i] == ')') s.insert(s.begin()+i, '('), i++;
        //cerr << "paren " << s << endl;

        forn(i, si(s)) if (s[i] == '(') s.insert(s.begin()+i+1, '1');
        //cerr << "nums entre () " << s << endl;

        forn(i, si(s)) 
            if (s[i] == '+' && i < si(s) && s[i+1] == '+') 
                s.insert(s.begin()+i+1, '1');
        if (s.front() == '+') s.insert(s.begin(), '1');
        if (s.back() == '+') s.push_back('1');
        //cerr << "nums entre + " << s << endl;

        forn(i, si(s)) 
            if (s[i] == ')' && i+1 < si(s) && s[i+1] != '+') 
                s.insert(s.begin()+i+1, '+');
            else if (s[i] == '(' && i > 0 && s[i-1] != '+') 
                s.insert(s.begin()+i, '+');

        cout << s << endl;
        //cerr << endl;
    }

    return 0;
}
