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

const int maxn = 1e5+10;
ll seq[maxn];

#define tipo ll
struct Fenwick {
  static const int sz = (1 << 17) + 1;
  tipo t[sz];
  void adjust(int p, tipo v){ // p en [1, sz), O(lg n)
    for(int i = p; i < sz; i += (i & -i)) t[i] += v;
  }
  tipo sum(int p){ // Suma acumulada en [1, p], O(lg n)
    tipo s = 0;
    for(int i = p; i; i -= (i & -i)) s += t[i];
    return s;
  }
  tipo sum(int a, int b){ return sum(b) - sum(a - 1); }
  // Obtiene el menor valor con suma acumulada >= x
  // Para mayor, llamar a getind(v + 1) - 1, creo
  int getind(tipo v) {
    int x = 0;
    for(int d = 1 << 17; d; d >>= 1)
        if(t[x|d] < v){
            x |= d;
            v -= t[x];
        }
    return x + 1;
  }
}bit;


int main() {
    fastio;
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);

    int n; cin >> n;
    forsn(i,1,n+1){
        cin>> seq[i];
        bit.adjust(i,seq[i]);    
    }


    for(int i=2;i<n+1;i+=2){
        bit.adjust(i-1,-(bit.t[i]-seq[i]));
    }
    string s="";
    forsn(i,1,n+1){
        cout <<s << bit.sum(i,i);
        s=" ";
    }
    cout << endl;

    return 0;
}
