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
typedef long long int tint;

int main() {
    fastio;

    char cons[] = {'B','C','D','G','K','N','P','T'};
    bool hard[26];
    forn(i,26) hard[i] = 0;
    forn(i,8) hard[cons[i]-'A'] = 1;
    int dif = 'a'-'A';

    string s;

    while(cin >> s){
        bool f = s[0] < 'a';
        string r = "";
        int j,m = 30;
        forn(i,8){
            int e = s[0]-cons[i];
            if(!f) e -= dif;
            int d = abs(e);
            if(d < m){
                m = d;
                j = i;
            }
        }
        if(f) r += cons[j];
        else r += cons[j]+dif;

        char t = r[0];
        if(f) t += dif;
        bool ok = 0;
        forsn(i,1,si(s)){
            if(s[i] == '-') ok = 1;
            else if(ok && hard[s[i]-'a']) r += t;
            else r += s[i];
        }

        char l = r[si(r)-1];
        if(f && si(r) == 1) l += dif;
        if(hard[l-'a']){
            m = 30; char k;
            for(auto i : {'a','o','u'}){
                int d = abs(l-i);
                if(d < m){
                    m = d;
                    k = i;
                }
            }
            r += k;
            r += 'h';
        }

        cout << r << ' ';
    }
    cout << endl;
    return 0;
}
