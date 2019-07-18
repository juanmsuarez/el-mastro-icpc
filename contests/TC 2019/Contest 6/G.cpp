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

#define N 4000

bitset<N> A[N],B[N],C[N];

string hextobin(string s,int n){
    stringstream res,aux;
    int b;
    for(char c:s){
        aux << hex <<c;
        aux >> b;
        D(b);
        res << bitset<4>(b).to_string();
    }
    return res.str().substr(0,n-3+(n+3)%4);
}

void readInput(bitset<N> matrix[N],int n){
    forn(i,n){
        string s;
        cin >>s;
        matrix[i]=bitset<N>(hextobin(s,n));
    } 
}

int main() {
	fastio;
	
    int n;
    cin >> n;

    string s;
    cin >> s;
    cout << hextobin(s,n) << endl;

    //readInput(A,n);
    //readInput(B,n);
    //readInput(C,n);

	
	return 0;
}

