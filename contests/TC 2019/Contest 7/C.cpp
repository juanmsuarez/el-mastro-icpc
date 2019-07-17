
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl;
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (int)(n-1); i >= (int) s;i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb emplace_back
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;


int main(){
        fastio;

        string s;
        double res=0;
        vector<pair<double,double>>points;
        while(getline(cin,s)){
            D(s);
            int ind=si(s)-1;
            while(s[ind-1]!='(')ind--;
            s=s.substr(ind);
            ll sep = s.find(',');
            double x1= stod(s.substr(0,sep));
            s=s.substr(sep+1);
            sep =s.find(')');
            double x2= stod(s.substr(0,sep));
            points.pb(x1,x2);
        }
        forsn(i,1,si(points)){
            res+=hypot(abs(points[i].first-points[i-1].first),abs(points[i].second-points[i-1].second));
            cout << fixed << setprecision(3) <<"The salesman has traveled a total of " <<  res << " kilometers." << endl;
        }

        

        return 0; 
}
