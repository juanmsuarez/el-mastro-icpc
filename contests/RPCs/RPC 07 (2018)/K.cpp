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

const int MAXN = 1e5+10, INF = 1e9+1;
//Para non-increasing, cambiar comparaciones y revisar busq binaria
//Given an array, paint it in the least number of colors so that each color turns to a non-increasing subsequence.
//Solution:Min number of colors=Length of the longest increasing subsequence
int N, a[MAXN];//secuencia y su longitud
pii d[MAXN+1];//d[i]=ultimo valor de la subsecuencia de tamanio i
int p[MAXN];//padres
vector<int> R;//respuesta
int lis(){//O(nlogn)
	d[0] = pii(-INF, -1); forn(i, N) d[i+1]=pii(INF, -1);
	forn(i, N){
		int j = upper_bound(d, d+N+1, pii(a[i], INF))-d;
		if (d[j-1].first <= a[i]&&a[i] < d[j].first){
			p[i]=d[j-1].second;
			d[j] = pii(a[i], i);
		}
	}
	R.clear();
	dforsn(i, 0, N+1) {
        if(d[i].first!=INF){
            reverse(R.begin(), R.end());
            return i;//longitud
        }
    }
	return 0;
}

int main() {
    fastio;

    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x2 < x1) {
        swap(x1, x2);
        swap(y1, y2);
    }
    bool inv = false;
    if (y2 < y1) {
        inv = true;
        y1 = -y1;
        y2 = -y2;
    }


    vector<pii> v;
    forn(i, n) {
        int x, y; 
        cin >> x >> y;
        if (inv) y = -y;

        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) 
            v.pb(x, y);
    }    
    sort(all(v));
    
    N = 0;
    for (pii pt : v) {
        a[N++] = pt.second;
    }

    cout << lis() << endl;    

    return 0;
}
