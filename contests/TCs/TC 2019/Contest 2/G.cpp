#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<(int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=(int)s;i--)
#define dforn(i,n) dforsn(i,0,n)

#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second 
#define fst first
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

string s; 
int i, n;

bool adv() {
    bool res = false;
    while (i + 3 <= n && s.substr(i, 3) == "WUB") i += 3, res = true;
    return res;
}

int main(){
    fastio;

    cin >> s;
    n = si(s);

    string t; i = 0;
    adv();
    while (i < n) {
        if (adv()) {
            if (i != n) t += ' ';
        }
        else {
            t += s[i];
            i++;
        }
    }

    cout << t << endl;

    return 0;
}
