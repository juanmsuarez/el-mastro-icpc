#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

vector<pii>seq;

int cantminmax(int comp,int op,int l){
	deque<pii>q;
	q.push_back(seq[0]);
	int cant=0;
	forsn(i,1,si(seq)){
		while(!q.empty() && q.front().first+l<seq[i].first)q.pop_front();
		if(!q.empty() && seq[i].second*comp>q.front().second*comp)cant++;
		while(!q.empty() && seq[i].second*op>q.back().second*op)q.pop_back();
		q.push_back(seq[i]);
	}
	return cant;
}
int cantavg(int comp,int l){
	int j=0;
	int sum=seq[0].second;
	int cant =0;
	forsn(i,1,si(seq)){
		while(j<i&&seq[j].first+l<seq[i].first)sum-=seq[j++].second;
		if(j!=i&& seq[i].second*comp*(i-j)>sum*comp)cant++;
		sum+=seq[i].second;
	}
	return cant;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);

#ifdef LOCAL 
	freopen("input.txt","r",stdin); 
#endif

	int n;
	while(cin >> n){
		seq =vector<pii>(n);
		forn(i,n){
			int t,v;
			cin >> t>>v;
			seq[i]=mp(t,v);
		}

		int c;
		cin >> c;
		forn(_,c){
			string r,f;
			int l;
			cin >> r >> f >> l;
			int comp = (r=="gt"?1:-1);
			int op = (f=="max"?1:-1);
			if(f=="min")cout << cantminmax(comp,op,l)<<endl;
			if(f=="max")cout << cantminmax(comp,op,l)<<endl;
			if(f=="avg")cout << cantavg(comp,l)<<endl;
		}
	}



	return 0;
}
