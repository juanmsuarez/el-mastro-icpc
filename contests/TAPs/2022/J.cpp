#include <bits/stdc++.h>

using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

int main() {
    fastio;

    map<int, int> mazo;
    forsn(i, 1, 14) {
        mazo[i]=4;
    }

    int n;
    cin >> n;

    int juan =0, maria = 0;
    int a, b;
    cin >> a >> b;
    mazo[a]--;
    mazo[b]--;
    a = min(a, 10);
    b = min(b, 10);
    juan = a + b;
    cin >> a >> b;
    mazo[a]--;
    mazo[b]--;
    a = min(a, 10);
    b = min(b, 10);
    maria = a + b;

    forn (i, n) {
        cin >> a;
        mazo[a]--;
        a = min(a, 10);
        juan += a;
        maria += a;
    }

    vi choices;
    for (auto [car, cant] : mazo) {
        forn (i, cant) {
            choices.pb(min(10,car));
        }
    }


    int carta = -1;
    for (int k : choices) {
        if (maria + k == 23 ||
            (maria + k <= 23 && juan + k > 23)) {
            carta = k;
            break;
        }
    }
    cout << carta << endl;

    return 0;
}

