#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = (int) s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
using namespace std;

int main(){
	int n;
	while(cin >> n && n!=0){
		int sol=0;
		forn(i,n){
			forn(j,n){
				sol+=n-max(i,j);	
			}
		}
		cout << sol << endl;
	}
   return 0;
}
