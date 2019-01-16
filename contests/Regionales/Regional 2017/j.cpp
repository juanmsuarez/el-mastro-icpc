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

const int MAXN = 1e5+10;
int n;
bool equivalente[MAXN], checked[MAXN];
string s;

bool can(int start, int k) {
	int i = start;

	do {
		checked[i] = true;
		i = (i+k)%n;
	}
	while (s[i] == 'R' && i != start);

	return i == start;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	/*	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	*/
	
	cin >> s;
	n = si(s);
	int ans = 0;

	for (int k = 1; k < n; k++) {
		if (equivalente[k] || n%k != 0) continue;

		bool could = false;
		fill(checked, checked+n, false);

		forn(i, n) 
			if (s[i] == 'R' && !checked[i] && can(i, k)) {
				could = true;
				break;
			}

		if (could)
			for (int ks = k; ks < n; ks += k) {
				if (!equivalente[ks]) {
					equivalente[ks] = true;
					ans++;
				}
			}
	}

	cout << ans << endl;

	return 0;
}
