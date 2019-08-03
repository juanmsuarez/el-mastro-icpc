#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = (int) s; i < (int)n;i++)
#define dforsn(i,s,n) for(int i = (int) (n-1); i >= (int)s;i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
using namespace std;

#define pb emplace_back
#define si(v) (int)((v).size())
#define fst first
#define snd second
typedef  vector<int> vi;
typedef  pair<int,int> pii;

vi prefix_function(string &s){
    int n=si(s);vi pi(n);
    forsn(i,1,n){
        int j = pi[i-1];
        while (j>0 && s[i] != s[j])j= pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi;
}

int main(){
    string s;
    cin >> s;
    vi borde = prefix_function(s);
    //forn(i,si(borde))cerr << borde[i] << " ";
    //cerr << endl;

    vi cant(si(borde),1);
    int b = si(borde)-1;
    vector<pii> res;
    dforn(i,si(s)){
        if(i==b){
            res.emplace_back(b+1,cant[b]);
            b=borde[b]-1;
        }
        if(borde[i])cant[borde[i]-1]+=cant[i];
    }

    cout << si(res) << endl;
    dforn(i,si(res))cout << res[i].first << " " << res[i].second << endl;



    return 0;

}
