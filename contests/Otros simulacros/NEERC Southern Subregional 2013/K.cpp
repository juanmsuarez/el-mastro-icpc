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

vi gleft,gright,memo;
vector<pii> sol;

int n;

int dp(int i){
    if(i>=n)return 0;
    if(memo[i]!=-1)return memo[i];
    int &res = memo[i] = 0;
    int l = dp(i+gleft[i]);
    int r = dp(i+gright[i]);
    //D(i);
    if(l<=r){
        res= 1+l;
        sol[i]=mp(i+gleft[i],i+1);
        //D(gleft[i]);
    }else{
        res= 1+r;
        sol[i] = mp(i+1,i+gright[i]);
        //D(gright[i]);
    }
    //cerr << "dp " << i << "= "<<res<<endl;
    return res;
}

int main() {
    fastio;

    cin >> n;
    vi seq(n);
    forn(i,n)cin >> seq[i];
    gleft = vi(n);
    gright = vi(n);
    memo = vi(n,-1);
    sol = vector<pii>(n);
    
    int l=n,r=n;
    while(l>0){
        l--;
        int val=l+seq[l];
        r=min(val,r);
        gleft[l]=r-l;
    }
    l=0,r=0;
    while(l<n){
        while(r<n&&r+1-seq[r]<=l)r++;
        gright[l]=r-l;
        l++;
    }

    cout << dp(0)<<endl;
    int ind=0;
    while(ind<n){
        cout << sol[ind].first << " " << sol[ind].second << endl;
        ind = max(sol[ind].first,sol[ind].second);
    } 

    return 0;
}
