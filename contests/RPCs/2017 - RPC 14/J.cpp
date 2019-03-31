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

int a[30];
char m[30][30];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	int n;
	while (cin >> n) {
		fill(a, a+30, 0);

		forn(i, n) forn(j, n) {
			cin >> m[i][j];
			a[m[i][j]-'A']++;
		}

		int x = 0, y = 0;
		char c = 0;
		bool found = false;

		forn(i, 26) if (a[i] == 1) c = 'A' + i, found = true;
		
		if (found) {
			forn(i, n) forn(j, n) if (m[i][j] == c) x = i, y = j;
		}
		else {
			forn(i, n) forn(j, n) {
				int cnt = 0;	
				forn(k, n) {
					if (k != j)
						cnt += m[i][k] == m[i][j];
					if (k != i)
						cnt += m[k][j] == m[i][j];
				}
				if (cnt == 2) {
					c = m[i][j];
					x = i;
					y = j;
				}
			}	
		}

		forn(i, 26) if (a[i] == n-1) c = 'A' + i;

		cout << x+1 << ' ' << y+1 << ' ' << c << endl;
	}

	return 0;
}
