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

const int N = 1e6;
int lp[N+1],p[N/5],sp=0; // prime_density(n) ~= n/ln(n)
// lp (least prime) allows fast factorization of numbers <= N

void sieve(){ // O(N)
	forsn(i,2,N+1){
		if(lp[i] == 0) lp[i] = i, p[sp++] = i;
		for(int j=0; j < sp && p[j] <= lp[i] && i*p[j] <= N; j++) lp[i*p[j]] = p[j]; 
	}
}

int nxt[N+1];

int main() {
	fastio;

    sieve();

    for (int i = 0; i < 1000 && p[i] <= N; i++)
        for (int j = i; p[i] + p[j] <= N; j++)
            if ((p[j] - p[i]) % 2 == 0)
                nxt[p[i] + p[j]] = max(nxt[p[i] + p[j]], p[j] - p[i]);

    int x; cin >> x;

    int k = 0;
    while (x >= 4) x = nxt[x], k++;

    cout << k << endl;

        	
	return 0;
}
