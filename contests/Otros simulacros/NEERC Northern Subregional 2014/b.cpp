#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main() {
    fastio;
    freopen("buffcraft.in","r",stdin);
    freopen("buffcraft.out","w",stdout);

    int b,k,c,d;
    cin >> b >> k >> c >> d;
    vector<pair<ll,int>> direct(c),percent(d);
    forn(i,c){
        cin >> direct[i].first;
        direct[i].second = i+1;
    }
    forn(i,d){
        cin >> percent[i].first;
        percent[i].second = i+1;
    }

    sort(all(direct));
    reverse(all(direct));
    sort(all(percent));
    reverse(all(percent));
    
    vector<ll> prefDir(c+1,0), prefPer(d+1,0);
    ll bestDir=0,bestPer=0,res=b*100;
    forn(i,c){
        prefDir[i+1]+=prefDir[i]+direct[i].fst;
        D(prefDir[i+1]);
    }
    forn(i,d){
        prefPer[i+1]+=prefPer[i]+percent[i].fst;
        D(prefPer[i+1]);
    }

    int maxN = min(k,c);
    forn(i,maxN+1){
        int actDir=i,actPer=min(d,k-i);
        D(actDir);
        ll total = ((ll)b+prefDir[actDir]) * (prefPer[actPer]+100ll);
        D(total);
        if(total > res){
            res= total;
            bestDir = actDir;
            bestPer = actPer;
        }
    }
    
    cout << bestDir << " " << bestPer << endl;
    forn(i,bestDir)cout << direct[i].snd << " \n"[i == bestDir - 1];
    forn(i,bestPer)cout << percent[i].snd << " \n"[i == bestPer - 1];
    
    
    return 0;
}
