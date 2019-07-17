
#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int) n; i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) ((int)(a).size())


set<string> fr = {"Danil", "Olya", "Slava", "Ann" , "Nikita"};
map<string,int> cant;

int main(){
    string s;
    cin >> s;
    int n = si(s);
    forn(i,n){
        forn(j,n-i){
            string sub = s.substr(i,j+1);
            //cerr << sub << endl;
            if(fr.count(sub)){
                cant[sub]++;
            }
        } 
    }

    if(si(cant)==1 && cant.begin()->second == 1){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
