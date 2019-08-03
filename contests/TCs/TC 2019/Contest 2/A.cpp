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

    if(k>1 &&k%2){
        cout << "YES" << endl;
        cout << 2*k+4 << " " << k*k+2*k <<endl;
        cout << 1 << " " << k+3 << endl;

        forn(i,2){
            int offset = i*(k+2);
            cout << k+1+offset << " " << k+2+offset << endl;
            forn(j,k-1){
                int u = offset+2+j;
                cout << 1+offset <<" "<< u << endl;
                cout << k+1+offset << " " << u << endl;
                cout << k+2+offset << " " << u << endl;
                if(j%2 && j < k-2)cout << u << " " << offset + 2 + (j+1)%(k-1) << endl;
                forsn(offj,j+2,k-1){
                    int v = offset + 2 + (offj);
                    cout << u << " " << v <<endl;
                }
            }

        } 
    }
    else{
        if(k==1)cout << "YES\n2 1\n1 2" <<endl;
        else cout << "NO" << endl;
    }
	
	
	return 0;
}

