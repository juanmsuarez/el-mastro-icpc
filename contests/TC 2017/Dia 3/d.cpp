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

const int MAXN = 5e4+10;
int arr[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n, nc = 1;
	while (cin >> n && n != 0) {
		forn(i,n) arr[i] = i+1;
		
		int r;
		cin >> r;
		
		while (r--) {
			int i, j;
			cin >> i >> j;
			i--;
			j--;
			
			forn(k, (j-i+1)/2)
				swap(arr[i+k], arr[j-k]);
		}
		
		cout << "Genome " << nc++ << endl;
		int q;
		cin >> q;
		while (q--) {
			int a;
			cin >> a;
			forn(i, n) if (arr[i] == a) {
				cout << i+1 << endl;
				break;
			}
		}
	}	

	return 0;
}
