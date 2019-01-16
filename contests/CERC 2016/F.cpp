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

int res;
vi actual,wanted;

int unwrap(int i){
    int cuts=0;
    if(!actual[i])return cuts;
    cuts=1+unwrap(actual[i]);
    actual[i]=0;
    return cuts;
}

int main() {
	fastio;
	
	int n;
    cin >> n;
    actual = vi(n);
    wanted = vi(n);

    forn(i,n){
        cin >> actual[i];
        if(actual[i])actual[i]--;
    }
    forn(i,n){
        cin >> wanted[i];
        if(wanted[i])wanted[i]--;
    }

    res=0;

    forn(i,n){
        if(actual[i]!=wanted[i]){
            res+=unwrap(i);
            if(wanted[i]){
                res+=unwrap(wanted[i]);
                res++;
            }
            actual[i]=wanted[i];
        }
    }

    cout << res << endl;
	
	return 0;
}
