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

const int MAXN = 1000+10;

int Q[MAXN];

int main() {
	fastio;
	
    int N; cin >> N;

    int R = -1;

    forn(i,N){
        int x,y;
        cin >> x >>y; 
        forsn(j,x,y+1)Q[j]++;
    }
    forn(i,N+1)if(i==Q[i])R= max(R,i);

    cout << R << endl;
	
	return 0;
}

