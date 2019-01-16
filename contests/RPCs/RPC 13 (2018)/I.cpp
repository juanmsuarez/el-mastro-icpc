#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

string a[5];	
int r = 0, changes = 0, last = 4;
map<char,int> suit;

void r4(){
    int black = 0, red = 0;
    if(suit.count('C')) black += suit['C'];
    if(suit.count('S')) black += suit['S'];
    if(suit.count('H')) red += suit['H'];
    if(suit.count('D')) red += suit['D'];
    r += abs(black-red);
    changes++;
}

void r5(){
    if(r % 2 == 0){
        int sum = 0;
        forsn(i,1,r+1) if(r % i == 0) sum += i; 
        r += sum;
        changes++;
        last = 5;
    }
}

void r6(){
    int seven = 0;
    forn(i,5) if(a[i][0] == '7') seven++;
    if(seven == 4) r -= 121, changes++, last = 6;
}

void r7(){
    if(r >= 0){
        int l = 10;
        forn(i,5){
            int x = int(a[i][0]-'0');
            if(x >= 2 && x <= 9) l = min(l,x); 
        }
        r += l;
        changes++;
        last = 7;
    }
}

void r8(){
    if(r < 0) r = -r, changes++, last = 8;
}


void r9(){
    if(suit.count('D') && suit['D'] >= 3){
        r++;
        forn(i,5){
            if(a[i][0] == '6') a[i][0] = '9'; 
            else if(a[i][0] == '9') a[i][0] = '6'; 
            else if(a[i][0] == '2') a[i][0] = '5'; 
            else if(a[i][0] == '5') a[i][0] = '2'; 
        }
        changes++;
        last = 9;
    }
}

void r10(){
    vi v;
    forn(i,5){
        char c = a[i][0];
        int x = int(c-'0');
        if(x >= 2 && x <= 9) v.pb(x);
        else if(c == 'J') v.pb(11);
        else if(c == 'Q') v.pb(12); 
        else if(c == 'K') v.pb(13); 
        else if(c == 'A') v.pb(14);
        else v.pb(10);
    }
    sort(all(v));
    bool straight = 1;
    forn(i,4) if(v[i]+1 != v[i+1]) straight = 0;
    int As = 0;
    forn(i,5) if(a[i][0] == 'A') As++;
    int pre = r;
    if(straight){
        r += 5*As;
        changes++;
        if(r != pre) last = 10;
    }
}

void r11(){
    if(changes >= 8){
        int pre = r;
        r += __builtin_popcount(r);
        if(pre != r) last = 11;
    }
}

int superf(int n){
    int res=0;
    int div=2;
    while(div*div<=n){
        int superdiv = 1;
        while(n%div==0){
            superdiv*=div;
            n/=div;
        }
        div++;
        if(superdiv!=1)res*=superdiv;
    }
    if(n!=1)res*=n;
    return res;
}

void r13(){
    r*=2;
}

int main() {
	fastio;
	
	forn(i,5) cin >> a[i];

    forn(i,5){
        int x = int(a[i][0]-'0');
        if(x >= 2 && x <= 9) r += x;
        else x += 10; 
    }
   
    // 1:
    r++;
    changes++;
    int Js = 0;
    forn(i,5) if(a[i][0] == 'J') Js++;
    int first, y = int(a[0][0]-'0');
    if(y >= 2 && y <= 9) first = y;
    else first = 10; 
    r += Js*first;
    
    // 2:
    forn(i,5){
        int p = a[i][0] == '1' ? 2 : 1;
        suit[a[i][p]]++;
    }
    for(auto &i : suit) if(i.snd >= 2){
        r *= 2;
        changes++;
        break;
    }
    
    // 3:
    if(si(suit) == 4) r *= 2, changes++;
     
    r4();
    r5();
    r6();
    r7();
    r8();
    r9();
    r10();
    r11();
    
    // 12:
    bool two = 0;
    forn(i,5) if(a[i][0] == '2') two = 1;
    if(two){
        if(last == 4) r4();
        else if(last == 5) r5();       
        else if(last == 6) r6();       
        else if(last == 7) r7();       
        else if(last == 8) r8();       
        else if(last == 9) r9();       
        else if(last == 10) r10();       
        else if(last == 11) r11(); 

        // 13:
        r13();
        
    }
    cout << r << endl;
	return 0;
}
