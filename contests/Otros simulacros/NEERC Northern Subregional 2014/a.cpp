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

vi segm = { 6,2,5,5,4,5,6,3,7,6};

int time(int h,int m){
    int cant = segm[h/10]+segm[h%10]+segm[m/10]+segm[m%10];
    return cant;
}

int main() {
    fastio;
    freopen("alarm.in","r",stdin);
    freopen("alarm.out","w",stdout);
    
    int n;
    cin >> n;
    bool pos = false;

    forn(i,24){
        forn(j,60){
            if(!pos &&time(i,j)==n){
                pos=true;
                cout << (i<10?"0":"") << i << ":" << (j<10?"0":"") << j << endl;
            }
        }
    }
    if(!pos)cout << "Impossible" << endl;


    
    
    return 0;
}
