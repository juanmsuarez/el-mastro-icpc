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

    map<string, double> m;
    m["pink"] = 0;

    forn(_, n) {
        string a, b; 
        double ratio;
        cin >> a >> b >> ratio;

        if (m.count(b)) {
            if (m.count(a))
                m[a] = max(m[a], m[b]+log2(ratio));
            else
                m[a] = m[b] + log2(ratio);
        }
    }

    cout << fixed << setprecision(6);
    if (m.count("blue")) {
        double logBlue = m["blue"];
        if (logBlue <= 4)
            cout << min(pow(2, logBlue), 10.) << endl;
        else
            cout << 10. << endl;
    }
    else 
        cout << 0 << endl;

    return 0;
}
