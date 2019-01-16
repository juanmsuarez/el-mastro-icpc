#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MOD = 1e9+7;
ll can[16][16];

bool go(int from, int to) {
	forn(i, 4) {
		int a = 1<<i, b = 1<<(i+1);
		if (!(from&a)) {
			if (i < 3 && !(from&b) && !(to&a) && !(to&b)) i++;
			else if (!(to&a)) return false;
		}
		else if (to&a) return false;
	}

	return true;
}

void createMatrix() {
	forn(from, 16)
		forn(to, 16)
			if (go(from, to)) {
				can[from][to] = 1;

				/*
				cerr << "desde ";
				forn(i, 4) cerr << ((from&(1<<i)) != 0);
				cerr << " hasta ";
				forn(i, 4) cerr << ((to&(1<<i)) != 0);
				cerr << endl;
				*/
			}
    forn(i,16){
        forn(j,16){
            cerr <<can[i][j];
        }
        cerr << endl;
    }
}

void mul(ll a[16][16], ll b[16][16]) {
	ll res[16][16] = {{0}};
	forn(i,16) forn(j,16) forn(k,16) res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
	forn(i,16) forn(j,16) a[i][j] = res[i][j];
}

void powmat(ll a[16][16], ll n, ll res[16][16]) {
	forn(i, 16) forn(j, 16) res[i][j] = (i==j);
	while (n) {
		if (n&1) mul(res, a), n--;
		else mul(a, a), n/=2;
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	/*#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif*/
	
	createMatrix();	

	ll w;
	cin >> w;

	ll res[16][16];

	powmat(can, w, res);

	cout << res[0][0] << endl;

	return 0;
}
