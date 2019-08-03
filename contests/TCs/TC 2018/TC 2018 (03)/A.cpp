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
char Dec[]={'M','C','X','I'}, Fiv[]={'!','D','L','V'};

bool comp(pair<string,int> a,pair<string,int> b){
    if(si(a.first)!=si(b.first))return si(a.first)>si(b.first);
    return a.second>b.second;
}

string toRoman(int n){
    int digs[4];
    forn(i,4){
        digs[3-i]=n%10;
        n/=10;
    }

    string res="";
    forn(i,4){
        if(0<digs[i] && digs[i]<4)res.append(digs[i],Dec[i]);
        else if(digs[i]==4)res.append({Dec[i],Fiv[i]});
        else if(4<digs[i] && digs[i]<9)res+=string({Fiv[i]})+string(digs[i]-5,Dec[i]);
        else if(digs[i]==9)res.append({Dec[i],Dec[i-1]});
    }
    return res;
}

int main() {
    fastio;

    string s;
    cin >>s;
    map<char,int>cant;
    for(char c:s){
        if('a'<c && c < 'z')c-='a'-'A';
        cant[c]++;
    }
    vector<pair<string,int>>nums;
    dforsn(i,1,4000){
        string r = toRoman(i);
        bool can=true;
        map<char,int>digs;
        for(char c:r) digs[c]++;
        for(auto d:digs)can&=cant[d.first]>=d.second;
        if(can)nums.pb(r,i);
    }
    sort(all(nums),comp);
    if(si(nums))cout << nums.begin()->first << endl;
    
    return 0;
}
