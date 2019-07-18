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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

#define N 4000

bitset<N> A[N],B[N],C[N];

map<char,string> val{{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};
string hextobin(string s,int n){
    string res;
    for(char c:s){
        res+=val[c];
    }
    return res.substr(0,n);
}

void readInput(bitset<N> matrix[N],int n){
    forn(i,n){
        string s;
        cin >>s;
        matrix[i]=bitset<N>(hextobin(s,n));
    } 
}

bitset<N> matvecmul(bitset<N> matrix[N],bitset<N> vector,int n){
    bitset<N> res;
    forn(i,n){
        //cerr << scalar.to_string().substr(N-n) << " " << scalar.count() <<endl;
        res[n-1-i]=(matrix[i]&vector).count()&1;
    }
    return res;
}

#define LIMIT 0.6
int main() {
    //clock_t tStart = clock();
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
	fastio;

	
    int n;
    cin >> n;


    readInput(A,n);
    readInput(B,n);
    readInput(C,n);
    bitset<N> vec;
    bool eq=true;
    int tries = 10;

    mt19937 rng(time(0));
    do{
        vec = bitset<N>(0);
        forn(i,n)vec[i]=rng()%2; 
        eq &= matvecmul(A,matvecmul(B,vec,n),n)==matvecmul(C,vec,n);
        //cerr <<"vec="<< vec.to_string().substr(N-n) << endl << "res=" <<matvecmul(A,vec,n).to_string().substr(N-n)<< endl;
        //cerr << vec.to_string().substr(N-n) << " "<<matvecmul(A,matvecmul(B,vec,n),n).to_string().substr(N-n) << " " << matvecmul(C,vec,n).to_string().substr(N-n) << endl << endl;

    }while(eq &&tries--);

    cout << (eq ? "YES" : "NO") << endl;

	
	return 0;
}
