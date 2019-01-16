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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 5000+10;
int t[MAXN], w[MAXN];

bool f(int i, int j) {
    return w[i] < w[j]; 
}
struct comp {
    bool operator () (const int &i, const int &j) const {
        return w[i] > w[j];
    }
};

int main() {
    fastio;

    int n, a, b;
    cin >> n >> a >> b;

    vi A, B, AB;
    forn(i, n) {
        cin >> t[i] >> w[i];
        if (t[i] == 1) A.pb(i);
        else if (t[i] == 2) B.pb(i);
        else AB.pb(i);
    }

    sort(all(A), f); sort(all(B), f); sort(all(AB), f);

    multiset<int,comp> s;
    forn(i, min(si(A),a))
        s.insert(A[i]); forn(i, min(si(B),b)) s.insert(B[i]);
    int k = 0;
    while (k < si(AB) && si(s)<a+b) { 
        s.insert(AB[k]);
        k++;
    }

    while (k < si(AB) && !s.empty() && w[*s.begin()] > w[AB[k]]) {
        s.erase(s.begin());
        s.insert(AB[k]);
        k++;
    }

    int cant = si(s), sum = 0;
    for (int i : s) sum += w[i];

    cout << cant << ' ' << sum << endl;
    int inda = 1, indb = 1;
    for (int i : s)
        if (t[i] == 1) 
            cout << i+1 << ' ' << inda++ << endl;
    for (int i : s)
        if (t[i] == 2) 
            cout << i+1 << ' ' << a+indb++ << endl;
    for (int i : s)  
        if (t[i] == 3) {
            if (inda <= a)
               cout << i+1 << ' ' << inda++ << endl;
            else
                cout << i+1 << ' ' << a+indb++ << endl;
        }

    return 0;
}
