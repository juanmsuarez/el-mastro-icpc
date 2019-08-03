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
		freopen("in.txt","r",stdin); 
	#endif
	int r,c; cin >> r >> c;
	int t[r][c], w = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> t[i][j];
			
 	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int x = t[i][j];
			bool ok = 1;
			for(int k = 0; ok && k < j; k++)
				if(t[i][k] >= x) ok = 0;
			if(ok) w++;

			ok = 1;
			for(int k = j+1; ok && k < c; k++)
				if(t[i][k] >= x) ok = 0;
			if(ok) w++;
		
			ok = 1;
			for(int k = 0; ok && k < i; k++)
				if(t[k][j] >= x) ok = 0;
			if(ok) w++;
			
			ok = 1;
			for(int k = i+1; ok && k < r; k++)
				if(t[k][j] >= x) ok = 0;
			if(ok) w++;
			
		}
	}
	cout << w << endl;
	return 0;
}
