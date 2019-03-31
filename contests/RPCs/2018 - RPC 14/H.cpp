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

const int N = 40;
int n;
char a[N][N];
string base;

bool check1() {
    bool ans = true;
    forn(i, n) {
        string act;

        forn(j, n) act += a[i][j];
       
        sort(all(act));

        if (act != base) ans = false; 
    }
    return ans; 
}

bool check2() {
    string act;
    forn(i, n) act += a[i][0];
    return act == base;
}

void transpose() {
    char b[N][N];
    forn(i, n) forn(j, n) b[i][j] = a[j][i];
    forn(i, n) forn(j, n) a[i][j] = b[i][j];
}

int main() {
	fastio;
	
    cin >> n;
    forn(i, n) forn(j, n) cin >> a[i][j];    

    forn(i, n) 
        if (i < 10) base += '0' + i;
        else base += 'A' + (i-10);

    bool latin = check1(), reduced = check2();
    transpose();
    latin &= check1(); reduced &= check2();
	
    if (latin) cout << (reduced ? "Reduced" : "Not reduced") << endl;
    else cout << "No" << endl;

	return 0;
}
