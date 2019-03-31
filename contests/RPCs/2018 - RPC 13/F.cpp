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

const int N = 1e3+10, M = 1e9+7;
bool v[N];
int n, k, memo[N][N][2];

inline int add(int a, int b){ return a+b < M ? a+b : a+b-M; }

bool getcarry(int n) {
    if (n < 2) return 0;
    else return 1;
}

int dp(int pos, int on, bool carry) {
    if (pos == n) return (on+carry) == k;

    int &res = memo[pos][on][carry];
    if (res != -1) return res;
    
    return res = add(dp(pos+1, on + (carry ^ v[pos]), getcarry(carry+v[pos])), 
                    dp(pos+1, on + (carry ^ v[pos] ^ true), getcarry(carry+v[pos]+true)));
}

int main() {
	fastio;
	
    cin >> n >> k;
    dforn(i, n) {
        char c; cin >> c;
        v[i] = c == '1';
    }

    fill(memo[0][0], memo[N][0], -1);
    cout << dp(0, 0, 0) << endl;
	
	return 0;
}
