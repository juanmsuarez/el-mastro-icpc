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

    int n;
    cin >> n;
    string s;
    cin >>s;
    D(s);

    bool lucky=true;
    int sum=0;
    forn(i,n/2){
        lucky&=s[i]=='4'||s[i]=='7';
        sum+=s[i]-'0';
        D(sum);
    }
    forsn(i,n/2,n){
        lucky&=s[i]=='4'||s[i]=='7';
        sum-=s[i]-'0';
        D(sum);
    }

    cout << (lucky && !sum ? "YES" : "NO") << endl;

    return 0;
}
