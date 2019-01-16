
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
    string a,b; cin >> b;
    int n = b.size();
    a = b;
    sort(all(b));
    forn(i,n) forsn(j,i,n){
        if(a[i] != b[i] && i != j && a[i] == b[j]){
            if(b[i] > b[j]) cout << i+1 << ' ' << j+1 << endl;
            else cout << j+1 << ' ' << i+1 << endl;
            swap(b[i],b[j]);
            break;
        }
    }
	return 0;
}
