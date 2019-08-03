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

multiset<pair<char,char>> blocks;

int main() {
    fastio;
    freopen("enchanted.in","r",stdin);
    freopen("enchanted.out","w",stdout);

    string s1,s2,t1,t2;
    cin >> s1 >> s2 >> t1 >> t2;
    reverse(all(s2));
    reverse(all(t2));

    forn(i,si(s1)){
        blocks.emplace(s1[i],s2[i]);
    }
    bool res=true;
    for(int i=0;res&&i<si(t1);i++){
        auto it = blocks.find(mp(t1[i],t2[i]));
        if(it==blocks.end()) res=false;
        else{
            blocks.erase(it);
        }
    }

    cout << (res?"Yes":"No") << endl;

    return 0;
}

