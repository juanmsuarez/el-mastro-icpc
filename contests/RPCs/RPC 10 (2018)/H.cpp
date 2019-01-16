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

int main() {
	fastio;
    int t;
    cin >> t;

    double l2 = log2(10), l5 = log2(10)/log2(5);
    int a,b;
    
    while(t--){
        int res=0;
        cin >> a >>b;
        res= min(a,b);
        a-=res;
        b-=res;

        res+= max(1,int(ceil(a/l2)+ceil(b/l5)));
        cout << res << endl;
    }

    return 0;
}
