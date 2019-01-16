#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i <(int)(n); i++)
#define forsn(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define si(v) ((int)v.size())
typedef vector<int> vi;

bool goB(vi a, vi b, int winsA, int winsB);

bool goA(vi a, vi b, int winsA, int winsB) {
    if (winsA + winsB == 3) {
        //cerr << (winsA >= 2 ? "win a" : "win b") << endl;
        return winsA >= 2;
    }
    bool ans = false;
    forn(i, si(a)) {
        bool can = true;
        forn(j, si(b)) {
            int u = a[i], v = b[j];
            //cerr << "juego A " << u << " " << v << endl;
            a.erase(a.begin()+i, a.begin()+i+1);
            b.erase(b.begin()+j, b.begin()+j+1);
            if ((u < v && !goA(a,b,winsA + 1,winsB))
                || (u > v && goB(a,b,winsA,winsB+1)))
                can = false;
            a.insert(a.begin()+i, u);
            b.insert(b.begin()+j, v);
        }
        ans |= can;
    }

    return ans;
}

bool goB(vi a, vi b, int winsA, int winsB) {
    if (winsA + winsB == 3) {
        //cerr << (winsB >= 2 ? "win b" : "win a") << endl;
        return winsB >= 2;
    }

    bool ans = false;
    forn(j, si(b)) {
        bool can = true;
        forn(i, si(a)) {
            int u = a[i], v = b[j];
            //cerr << "juego B " << u << " " << v << endl;
            a.erase(a.begin()+i, a.begin()+i+1);
            b.erase(b.begin()+j, b.begin()+j+1);
            if ((u < v && goA(a,b,winsA + 1,winsB))
                || (u > v && !goB(a,b,winsA,winsB+1)))
                can = false;
            a.insert(a.begin()+i, u);
            b.insert(b.begin()+j, v);
        }
        ans |= can;
    }

    return ans;
}

int main() {
    vi a(3);

    cin >> a[0] >> a[1] >> a[2];

    vi b;
    forsn(i,1,8) if (i != a[0] && i != a[1] && i != a[2]) b.pb(i);

    cout << (goA(a,b,0,0)? 'S' : 'N') << endl;

    return 0;
}
