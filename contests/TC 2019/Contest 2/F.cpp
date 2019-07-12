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

const int MAXP = 1000100;
int criba[MAXP];
void crearcriba(){
    int w[] = {4,2,4,2,4,6,2,6};
    for(int p = 25;p < MAXP;p+=10)criba[p]=5;
    for(int p = 9;p < MAXP;p+=6)criba[p]=3;
    for(int p = 4;p < MAXP;p+=2)criba[p]=2;
    for(int p = 7,cur=0;p*p<MAXP;p+=w[cur++&7])if(!criba[p]){
        for(int j=p*p;j<MAXP;j+= (p << 1))
            if(!criba[j])criba[j]=p;
    }

}

set<ll> tprimos;
void buscarprimos(){
    crearcriba();
    forsn(i,2,MAXP)if(!criba[i]){
        tprimos.insert(ll(i)*ll(i));

    }
}

int main(){
    fastio;

    buscarprimos();

    int n;
    cin >> n;

    forn(i,n){
        ll a;
        cin >> a;
        if(tprimos.count(a))cout << "YES" << endl;
        else cout << "NO" << endl;
    }



    return 0;
}
