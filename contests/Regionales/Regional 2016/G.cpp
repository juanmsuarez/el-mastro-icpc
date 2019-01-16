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

const int MAXN = 5e5+10, MAXA = 26+5;
int n, m, aparicion[MAXA], s[MAXN], t[MAXN], b[MAXN];

void kmppre() {
	int i = 0, j = -1; b[0] = -1;

	while (i < n) {
		while (j >= 0 && (t[i] != t[j] && !(t[i] > j && t[j] == -1))) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmp() {
	int i = 0, j = 0, match = 0;

	while (i < m) {
		while (j >= 0 && (s[i] != t[j] && !(s[i] > j && t[j] == -1))) j = b[j];
		i++; j++;

		if (j == n) {
			match++;
			j = b[j];
		}
	}

	return match;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	string w;

	while (cin >> w) {
		fill(aparicion, aparicion+26, -1);
		
		m = si(w);
		forn(i, m) {
			int ap = aparicion[w[i]-'a'];

			if (ap != -1)
				s[i] = i-ap;
			else
				s[i] = -1;

			aparicion[w[i]-'a'] = i;
		}

		fill(aparicion, aparicion+26, -1);
		cin >> n;
		forn(i, n) {
			int a;
			cin >> a;
			a--;				
							
			int ap = aparicion[a];

			if (ap != -1)
				t[i] = i-ap;
			else
				t[i] = -1;

			aparicion[a] = i;
		}

		kmppre();
		cout << kmp() << endl;		
	}

	return 0;
}
