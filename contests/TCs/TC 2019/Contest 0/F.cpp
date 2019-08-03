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

vector<ship> fleet;

int main() {
	fastio;
	
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fleet = vector<ship>(n);
        forn(i,n){
            cin >> ship[i].x >> ship[i].y >> ship[i].z >> ship[i].p;
        }
        double lo=0,hi=INF;
        while(lo-hi>EPS){
            double P = (lo+hi)/2.0;
            vi soluSpace = fleet.first().getPlanes(P);
            forsn(i,1,n){
                vi octa = fleet[i].getPlanes(P);
                forn(j,8)soluSpace[j] = min(soluSpace[j],octa[j]);
            }
            
        }

    }
	
	return 0;
}

