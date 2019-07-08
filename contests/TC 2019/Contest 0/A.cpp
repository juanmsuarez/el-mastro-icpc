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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int S = 2;
int temp[S][S];
void mul(int a[S][S], int b[S][S]){
    forn(i, S) forn(j, S) temp[i][j] = 0;
    forn(i, S) forn(j, S) forn(k, S) temp[i][j]+=a[i][k]*b[k][j];
    forn(i, S) forn(j, S) a[i][j]=temp[i][j];
}
void powmat(int a[S][S], ll n, int res[S][S]){
    forn(i, S) forn(j, S) res[i][j]=(i==j);
    while(n){
        if(n&1) mul(res, a), n--;
        else mul(a, a), n/=2;
    } 
}

int main() {
	fastio;
	

	
	return 0;
}
