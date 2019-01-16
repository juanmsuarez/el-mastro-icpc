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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int maxn = 1e5;
int level[maxn];
vector<vector<pii>> shop;

int main() {
    fastio;
	int n,m;
	while(cin >> n >> m){
		forn(i,n) cin >> level[i];
		shop.resize(m);
		forn(i,m){
			int l,s,c; cin >> l >> s >> c; l--;
			if(s >= level[l]) shop[l].pb(s,c);
		}
		int r = 0;
		if(shop[0].empty()) r = -1; 
		if(r == 0) forn(i,n){
			int s = level[i], o = i;
			forsn(j,i+1,n){
				if(shop[j].empty()){
					i++;
					s += level[j];
				}
				else break;
			}
			int c = INT_MAX;
			for(pii &p : shop[o])
				if(p.first >= s && p.second < c) c = p.second;
			if(c == INT_MAX){
				r = -1;
				break;
			} else r += c;
		}
		cout << r << endl;
		shop.clear();
	}
    return 0;
}
