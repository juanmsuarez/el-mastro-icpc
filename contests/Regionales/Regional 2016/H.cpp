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

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	int n, k;
	while (cin >> n >> k) {
		priority_queue<int, vector<int>, greater<int>> pq;
	
		int cost = 0, free = 0;
		forn(i, n) {
			int c;
			cin >> c;

			if (free == k) {
				pq.push(c);
				free = 0;
			}
			else {
				if (!pq.empty() && pq.top() < c) {
					cost += pq.top();
					pq.pop();

					pq.push(c);
				}
				else cost += c;

				free++;
			}
		}

		cout << cost << endl;
	}

	return 0;
}
