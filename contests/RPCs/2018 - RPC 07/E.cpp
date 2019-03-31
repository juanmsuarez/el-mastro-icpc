#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

int main() {
    fastio;

    int n;
    cin >> n;   

    vi seq(n);
    forn(i,n)cin >> seq[i];

    sort(all(seq));
    reverse(all(seq));

    int a=0,b=0;
    for(int i=0;i<si(seq);i+=2)a+=seq[i];
    for(int i=1;i<si(seq);i+=2)b+=seq[i];
    cout << a <<" "<< b<<endl;

    return 0;
}
