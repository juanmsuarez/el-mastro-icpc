#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
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

const int MAXN=1e5+10;
vector<pii>query(MAXN);
vi penalty(MAXN,0);
vector<pii>teams(MAXN,mp(0,0));
vi AC(MAXN,0),lessp(MAXN,0);

int main() {
    fastio;

    int n,m;
    cin >> n >>m;
    int prob=0;
    forn(i,m){
        int t,p;
        cin >> t >> p;
        query[i]=mp(--t,p);
        if(!t){
            prob++;
            penalty[prob]=penalty[prob-1]+p;
        }
    }
    int pos=1;
    pii &u = teams[0];
    forn(i,m){
        int t=query[i].first;
        pii &v = teams[t];
        if(t){
            if(v.second<penalty[v.first])lessp[v.first]--;
            if(v.first)AC[v.first]--;
            v.first++;
            AC[v.first]++;
            v.second+=query[i].second;
            if(v.second<penalty[v.first])lessp[v.first]++;
            if((v.first==u.first+1&& (v.second-query[i].second>=u.second))|| (v.first==u.first&&v.second<u.second))
                pos++;
        }
        else{
            pos+=-lessp[u.first]-AC[u.first+1]+lessp[u.first+1];
            u.first++;
            u.second+=query[i].second;
        }
        cout << pos << endl;
    }
            

    return 0;
}
