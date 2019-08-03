#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

int main() {
    fastio;

    string _;
	int c; cin >> c; getline(cin, _);
	while(c--){
		string s;
		getline(cin,s);
		map<char,int> m;
		forn(i,si(s)) if(s[i] != ' ') m[s[i]]++;
		int d = 0; char x; bool ok;
		for(auto &i : m){
			if(i.second == d) ok = 0;
			else if(i.second > d){
				ok = 1;
				d = i.second;
				x = i.first;
			}
		} 
		if(ok){
			d = (x - 'E' + 26) % 26;
			cout << d << ' ';
			forn(i,si(s)) cout << (s[i] == ' ' ? ' ' : char((s[i]-'A'-d+26)%26 + 'A')); 
			cout << endl; 
		} else cout << "NOT POSSIBLE\n" << endl;
	}
    return 0;
}
