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
	
    int n;
    cin >> n;
    vector<ll> seqG(n),seqA(n);
    forn(i,si(seqG))cin >> seqG[i];
    forn(i,si(seqA))cin >> seqA[i];

    vector<ll> difG(n-1),difA(n-1);
    forn(i,n-1){
        difG[i]=abs(seqG[i]-seqG[i+1]);
        difA[i]=abs(seqA[i]-seqA[i+1]);
    }
    sort(all(difG));
    sort(all(difA));
   // forn(i,n-1)cerr << difG[i] << " ";
   // cerr << endl;
   // forn(i,n-1)cerr << difA[i] << " ";
   // cerr << endl;

    cout << (seqG[0]==seqA[0] && seqG.back() == seqA.back() &&difA == difG ? "Yes" : "No") << endl;
	
	return 0;
}

