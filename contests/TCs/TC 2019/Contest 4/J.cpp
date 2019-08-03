
#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using pii = pair<int,int>;

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--){
        int w,h,n;
        cin >> w >> h >>n;
        vector<bool> rows(w,0), cols(h,0);
        forn(i,n){
            int wi,hi;
            cin >> wi >> hi;
            rows[wi-1]=1;
            cols[hi-1]=1;
        }
        ll width=0,height=0;
        ll wact=0,hact=0;
        forn(i,w){
            if(rows[i])wact=0;
            else wact++;
            width=max(wact,width);
        }
        forn(i,h){
            if(cols[i])hact=0;
            else hact++;
            height=max(hact,height);
        }

        cout << width*height << endl;
    }

    return 0;
}
