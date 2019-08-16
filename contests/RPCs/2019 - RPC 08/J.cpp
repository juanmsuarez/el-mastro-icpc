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

bitset<10> buttons;

bool cantype(int n){
    if(n==0)return buttons[0];
    while(n){
        if(!buttons[n%10])return false;
        n/=10;
    }
    return true;
}

int main() {
	fastio;

    buttons.set();
	
	int n;
    cin >> n; 

    forn(i,n){
        int a;
        cin >> a;
        buttons.reset(a);
    }

    int t;
    cin >> t;

    int res = 1000;

    forn(i,1000){
        if(cantype(i))res = min(res,abs(t-i));
    }

    cout << res << endl;

	return 0;
}

