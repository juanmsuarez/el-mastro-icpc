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

bool esVocal(char c) {
	return string("aeiou").find(c) != string::npos;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("input.txt","r",stdin); 
	#endif
	
	string s;
	cin >> s;

	int i = 0, j = si(s)-1, dir = 1, cant = 1, vocales = 0;

	for (char c : s)
		vocales += esVocal(c);

	if (vocales == 0) return cout << 1 << endl, 0;

	while (i != j) {
		if (!esVocal(s[j])) j -= dir, cant++;
		else if (esVocal(s[i])) {
			i += dir;
			dir *= -1;
			swap(i, j);
			cant = 1;
		}
		else {
			cant = 0;
			break;
		}
	}

	cout << cant << endl;

	return 0;
}
