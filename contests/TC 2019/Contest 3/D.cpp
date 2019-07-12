
#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s, n) for (int i = (int)s; i < (int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


vi prefix_function(string &s){
    int n = si(s);vi pi(n);
    forsn(i,1,n){
        int j = pi[i-1];
        while(j>0 && s[i] != s[j])j = pi[j-1];
        if(s[i]==s[j])j++;
        pi[i] = j;
    }
    return pi;
}

bool find_occurrence(string &s,string &t){
    vi pre = prefix_function(t);
    int n = si(s),m = si(t),j=0;
    forn(i,n){
        while(j>0 && s[i] != t[j])j = pre[j-1];
        if(s[i] == t[j])j++;
        if(j==m){
            return true;
        }
    }
    return false;
}

int getBorde(string &a,string &b){
    string tmp = b+a;
    return min(min(prefix_function(tmp).back(),si(a)),si(b));
}


int main() {
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    vi inds = {0,1,2};

    //string a = "abra", b = "abracadabra";
    //cerr << find_occurrence(b,a) << endl;

    int res = si(s[0])+si(s[1])+si(s[2]);

    do{
        string s0 = s[inds[0]],s1 = s[inds[1]], s2 = s[inds[2]];
        string act = s0;
        if(find_occurrence(s0,s1))act = s0;
        else{
            int borde = getBorde(s0,s1);
            act = s0+s1.substr(borde); 
            //cerr << act << endl;
        }
        if(find_occurrence(act,s2))res = min(res,si(act));
        else{
            int borde = getBorde(act,s2);
            int sz = si(act) + si(s2) - borde;
            res = min(res,sz);
        }            
    }while(next_permutation(all(inds)));

    cout << res << endl;
}
