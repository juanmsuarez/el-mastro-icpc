
#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
    #define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int main() {
	fastio;

    int n;
    cin >> n;
    double res=0;
    forn(i,n){
        double a;
        cin >> a;
        res+=(!a?2.0:(1.0/a));
    }
    cout << fixed << setprecision(7) << res << endl;

	return 0;
}
