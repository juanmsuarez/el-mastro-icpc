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

int main() {
	fastio;

    int k;
    cin >>k;

    if(k%2){
        cout << "YES" << endl;
        cout << 4*k+4 << " " << 2*k*k+2*k <<endl;
        cout << 1 << " " << 2*k+3 << endl;

        forn(i,2){
            int offset = i*(2*k+2);
            forn(j,k-1){
                int u = offset+2+j;
                cout << 1+offset <<" "<< u;
                cout << k+1+offset << " " << u;
                cout << k+2+offset << " " << u;
                if(j%2)cout << u << " " << ;
                forsn(jj,k-1){
                    int v = 
                }
            }

        }

    }
	
	
	return 0;
}

