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

const int MAXN = 100+10;
int n;
char a[MAXN][MAXN], temp[MAXN][MAXN];
map<char,char> rotateChar, flipChar;
string rots = "<^>vooooxxxx|-|-/\\/\\", flips = "<^v>ooxx|-//\\\\";

void flip() {
	forn(i, n) forn(j, n) a[i][j] = flipChar[a[i][j]];

	forn(i, n) forsn(j, i+1, n)
		swap(a[i][j], a[j][i]);
}

void rotate() {
	forn(i, n) forn(j, n) a[i][j] = rotateChar[a[i][j]];

	forn(i, n) forn(j, n) temp[j][n-1-i] = a[i][j];
	memcpy(a, temp, sizeof(a));	
}

void print() {
	forn(i, n) {
		forn(j, n)
			cout << a[i][j];
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	for (int i = 0; i < si(rots); i += 4)
		forn(j, 4)
			rotateChar[rots[i+j]] = rots[i+(j+1)%4];

	for (int i = 0; i < si(flips); i += 2)
		forn(j, 2)
			flipChar[flips[i+j]] = flips[i+(j+1)%2];
	
	while (cin >> n) {
		forn(i, n) forn(j, n) cin >> a[i][j];
		string s;
		getline(cin, s);
		getline(cin, s);

		int rot = 0, f = 0;

		forn(i, si(s)) {
			switch (s[i]) {
				case '<': f ? rot++ : rot += 3; break;
				case '>': f ? rot += 3 : rot++; break;
				case '\\': f^=1; break;
				case '/': f^=1;  rot += 2; break;
				case '|': f^=1; f ? rot += 3 : rot++; break;
				case '-': f^=1; f ? rot++ : rot += 3; break;
				default: break;
			}
		}

		rot = rot%4;
		f = f%2;

		//cerr << "inicial" << endl;
		//print();

		forn(i, rot) {
			rotate();

			//cerr << "luego de rot" << endl;
			//print();
		}

		if (f) {
			flip();
			//cerr << "luego de flip" << endl;
			//print();
		}

		print();
	}

	return 0;
}
