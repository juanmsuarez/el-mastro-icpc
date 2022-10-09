#include <bits/stdc++.h>

using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

int main() {
    fastio;
    
    int total = 0, k = 0, n;
    string s;
    cin >> n >> s;
    
    vi sec;
    
    forn(i,n){
			if(s[i] == 'b'){
					sec.pb(k);
					k = 0;
			}
			else
				k++;
	}
	sec.pb(k);
	forn(i,si(sec)){
			if(sec[i] > 1) total += sec[i];
	}
	
	cout << total << endl;
    

    return 0;
}
