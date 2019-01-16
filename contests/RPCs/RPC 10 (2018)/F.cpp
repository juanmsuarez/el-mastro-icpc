#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
    #define endl '\n'
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int divs[] = {2,3,4,7,13};
int mods[5][2];

int main() {
	fastio;
    //freopen("a.out","w",stdout);

    int a;
    while(cin >> a){
        int num =a;
        forn(i,5){
            mods[i][0]=0;
            mods[i][1]=1;
        }
        while(a--){
            forn(i,5){
                int pell = (2*mods[i][1]+mods[i][0])%divs[i];
                mods[i][0]=mods[i][1];
                mods[i][1]=pell;
            }
        }
        bool nothing=true;
        forn(i,5){
            nothing=nothing&&mods[i][0];
            if(!mods[i][0])cout << "Pell"<<"'" <<"s number "<<num <<" is divisible by " << divs[i] << endl;
        }
        if(nothing)cout << -1 << endl;
    }

	return 0;
}
