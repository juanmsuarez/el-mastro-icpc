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
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define endl '\n'
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

vi digu;

bool build(vi &rem,vi &num,int pos){
    forsn(i,pos,si(num)){
        int j=9;
        while(j>=0&&!rem[j])j--;
        if(j==-1)return false;
        num[i]=j;
        rem[j]--;
    }
    return true;
}

ll best(ll res,vi &num){
    ll n=0;
    forn(i,si(num)){
        n=n*10+num[i];
    }
    //cerr<<n<<endl;
    return max(n,res);
}

int main() {
    fastio;

    ll u;
    while(cin >> u){
        digu.clear();
        while(u>0){
            digu.pb(u%10);
            u/=10;
        }
        reverse(all(digu));
        ll res=0;
        forn(pos,si(digu)+1){
            vi rem(10,2);
            vi num(si(digu));
            forn(i,pos){
                num[i]=digu[i];
                rem[digu[i]]--;
            }
            if(si(digu)==pos){
                res=best(res,num);
                break;
            }
            int j=digu[pos]-1;
            while(j>=0&&!rem[j])j--;
            //cerr << j << endl;
            bool cont=rem[digu[pos]];
            if(j>=0){
                num[pos]=j;
                if(j!=0||pos)rem[j]--;
                if(build(rem,num,pos+1)){
                    res=best(res,num);
                }
            }
            if(!cont)break;
        }
        cout << res << endl;
    }


    return 0;
}
