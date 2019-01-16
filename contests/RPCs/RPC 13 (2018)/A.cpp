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

map<string,int> dice = { {"::::o::::",1}, {"o:::::::o",2}, {"::o:::o::",2}, {"::o:o:o::",3},{"o:::o:::o",3},{"o:o:::o:o",4},{"o:o:o:o:o",5},{"o:oo:oo:o",6},{"ooo:::ooo",6}};

int main() {
	fastio;
	
	string s="";
    
    forn(i,3){
        string a;
        cin >> a;
        s+=a;
    }

    if(dice.count(s))cout << dice[s] << endl;
    else cout << "unknown" << endl;
	
	return 0;
}
