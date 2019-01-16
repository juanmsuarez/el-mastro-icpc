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
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXC = 1e5+10;
int cantColor[MAXC];

int main() {
    fastio;

    set<pii> S;
    tint l, c, n; 
    cin >> l >> c >> n;

    cantColor[1] = l;
    S.insert(mp(0, -1));
    S.insert(mp(l-1, 1));

    while (n--) {
        int p, x;
        tint a, b;
        cin >> p >> x >> a >> b;

        tint s = cantColor[p];
        int m1 = (a + s*s%l)%l, m2 = (a + ((s+b)%l)*((s+b)%l)%l)%l;
        if (m2 < m1) swap(m1, m2);

        auto it = S.lower_bound(mp(m1, -c));

        // caso especial: estrictamente contenido en un intervalo
        if (it->second > 0 && it->first > m2) {
            S.insert(mp(m1-1, it->second));
            S.insert(mp(m2+1, -it->second));
            cantColor[it->second] -= m2-m1+1;
        }
        else {
            if (it->second > 0) { // incluye la parte final de un intervalo?
                auto prev = it;

                it++;

                cantColor[prev->second] -= prev->first - m1 + 1;
                S.insert(mp(m1-1, prev->second));

                S.erase(prev);
            }

            // incluye intervalos completos?
            while (it != S.end() && next(it)->first <= m2) {
                auto start = it, last = next(it);

                cantColor[last->second] -= last->first - start->first + 1;

                it = next(last);
                S.erase(start);
                S.erase(last); 
            }

            if (it != S.end() && it->first <= m2) { // incluye la parte inicial de un intervalo?
                S.insert(mp(m2+1, it->second));
                cantColor[-it->second] -= m2 - it->first + 1;

                S.erase(it);
            }
        }

        S.insert(mp(m1, -x));
        S.insert(mp(m2, x));
        cantColor[x] += m2-m1+1;
    }

    int best = 0;

    forsn(color, 1, c+1)
        if (cantColor[color] > best)
            best = cantColor[color];

    cout << best << endl;

    return 0;
}
