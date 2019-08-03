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

int main() {
    fastio;

    int n,q;
    cin >> n >> q;
    int cant=0;
    vi app(n,0);
    vi read(n,0);
    queue<int>qu;
    int pos=0;
    forn(i,q){
        int a,b;
        cin >> a>>b;
        if(a==1){
            cant++;
            qu.push(b-1);
            app[b-1]++;
        }else if(a==2){
            read[b-1]=pos+si(qu);
            cant-=app[b-1];
            app[b-1]=0;
        }
        else{
            while(pos<b){
                if(pos>=read[qu.front()]){
                    app[qu.front()]--;
                    cant--;
                }
                qu.pop();
                pos++;
            }
        }
        cout << cant<<endl;
    }


    return 0;
}
