#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1e4+10, MOD = 1e9+7;
int b[MAXN][MAXN];

int add(int a, int b) {
    return a+b >= MOD ? a+b-MOD : a+b;
}

int main() {
	fastio;

    forn(i, MAXN) b[0][i] = 1;
    forsn(i, 1, 1e4+1) {
        dforn(j, i+1)
            b[i][j] = add(b[i-j][j], b[i][j+1]);
    }

    int a;
    while (cin >> a)
        cout << b[a][0] << endl;

    return 0;
}
