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

map<int,int> mapa;

int main() {
    fastio;
    
    int res = 0;
    int n, nuevo; cin >> n;
    forn(i,n){
		cin >> nuevo;
		if(mapa[nuevo] == 0){
				mapa[nuevo-1]++;
				res++;
		}
		else{
			mapa[nuevo]--;
			mapa[nuevo-1]++;
		}
	}
	cout << res << endl;

    return 0;
}
