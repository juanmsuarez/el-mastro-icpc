#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;
typedef vector<pii> vii;

const int MAXK = (1<<20)+10;
bool can[MAXK];

void go(vi v, vii &sums) {
	forn(S, 1<<si(v)) {
		for (int T = S; ; T = (T-1)&S) {
			int sum = 0;

			forn(i, si(v))
				if (T & (1<<i))
					sum += v[i];
				else if (S & (1<<i))
					sum -= v[i];

			sums.pb(mp(sum, S));

			if (T == 0) break;
		}
	}
	sort(all(sums));
	sums.resize(unique(all(sums))-sums.begin());
}

int main() {
    fastio;

	int n;
	while (cin >> n) {
		fill(can, can+MAXK, false);

		vi A, B;
		forn(i, n) {
			int a;
			cin >> a;
			if (i < n/2)
				A.pb(a);
			else
				B.pb(a);
		}

		vii sumsA, sumsB;
		go(A, sumsA);
		go(B, sumsB);

		int i = 0, j = si(sumsB)-1, k = j;

		while (i < si(sumsA)) {
			while (j > 0 && sumsB[j].first > - sumsA[i].first) 
				j--;

			if (sumsB[j].first == -sumsA[i].first) {
				k = j;
				while (k > 0 && sumsB[k-1].first == sumsB[k].first) {
					can[sumsA[i].second | (sumsB[k].second<<si(A))] = true;
					k--;
				}
				can[sumsA[i].second | (sumsB[k].second<<si(A))] = true;
			}

			i++;
		}

		int ans = 0;
		forn(S, 1<<n) ans += can[S];
		cout << ans-1 << endl;
	}
			

    return 0;
}
