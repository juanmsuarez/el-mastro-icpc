
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
    int n,m;
    cin >> n;

    vi a(n);

    forn(i,n)cin >> a[i];
    cin >> m;
    vi b(m);
    forn(i,m)cin >> b[i];

    sort(all(a));
    sort(all(b));

    int i=0,j=0,res=0;
    while(i<si(a) && j<si(b)){
        if(abs(a[i]-b[j])<=1){
            i++,j++,res++;
        }
        else{
            if(a[i]<b[j])i++;
            else j++;
        }
    }

    cout << res << endl;
    //upsolving


}
