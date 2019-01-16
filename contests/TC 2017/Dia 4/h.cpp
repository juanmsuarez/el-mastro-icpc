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
typedef long long int tint;

const int MAXN = 2e3+10;
map<string, bool> ac[10];
map<string, int> subAct[10];
int nac[10];

double avsub[10], avtime[10];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int nc;
	cin >> nc;
	
	cout << fixed << setprecision(2);
	
	while (nc--) {
		int n;
		cin >> n;
		
		forn(i, 10) {
			ac[i].clear();
			subAct[i].clear();
			nac[i] = 0;
			avsub[i] = 0;
			avtime[i] = 0;
		}
		
		int time;
		char problem, res;
		string team;
		forn(i, n) {
			cin >> time >> team >> problem >> res;
			int p = problem - 'A';
			if (ac[p][team]) continue;
			subAct[p][team]++;
			
			if (res == 'A') {
				ac[p][team] = true;
				nac[p]++;
				avsub[p] += subAct[p][team];
				//cout << "Entro " << problem << " . Team " << team << " subm " << subAct[p][team] << endl;
				avtime[p] += time;
			}
		}
		
		forn(i, 9) {
			cout << char('A'+i) << ' ';
			if (nac[i] > 0) {
				cout << nac[i] << ' ' << avsub[i] / nac[i] << ' ' << avtime[i] / nac[i] << endl;
			}
			else 
				cout << 0 << endl;
		}
		
		if (nc)
			cout << endl;
	}

	return 0;
}
