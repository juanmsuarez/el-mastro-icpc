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

map<char, int> cant;
string comb[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int value[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

string make(int n) {
    string s;
    map<char, int> need;
    dforsn(i, 0, 13) {
        while (n >= value[i]) {
            n -= value[i];
            s = (s + comb[i]);

            for (char c : comb[i])
                need[c]++;
        }
    }

    for (auto p : need)
        if (p.second > cant[p.first])
            return "";
    return s;
}

int main() {
    fastio;

    string s; cin >> s;
    for (char c : s)
        cant[toupper(c)]++;

    string best;
    forsn(n, 1, 4000) {
        string t = make(n);
        if (t != "" && si(t) >= si(best)) best = t;
    }

    cout << best << endl;

    return 0;
}
