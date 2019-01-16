const int MAXN = 1e3+10;
#define rBOUND(x) (x<n? r[x] : 0)
//sa will hold the suffixes in order.
int sa[MAXN], r[MAXN], n;
string s; //input string, n=si(s)

int f[MAXN], tmpsa[MAXN];
void countingSort(int k){
    fill(f, f+MAXN, 0);
	forn(i, n) f[rBOUND(i+k)]++;
	int sum=0;
	forn(i, max(255, n)){
		int t=f[i]; f[i]=sum; sum+=t;}
	forn(i, n)
		tmpsa[f[rBOUND(sa[i]+k)]++]=sa[i];
	memcpy(sa, tmpsa, sizeof(sa));
}
void constructsa(){//O(n log n)
	n=si(s);
	forn(i, n) sa[i]=i, r[i]=s[i];
	for(int k=1; k<n; k<<=1){
		countingSort(k), countingSort(0);
		int rank, tmpr[MAXN];
		tmpr[sa[0]]=rank=0;
		forsn(i, 1, n)
			tmpr[sa[i]]=(r[sa[i]]==r[sa[i-1]] && r[sa[i]+k]==r[sa[i-1]+k] )? rank : ++rank;
		memcpy(r, tmpr, sizeof(r));
		if(r[sa[n-1]]==n-1) break;
	}
}
void print(){//for debug
	forn(i,n){
		cout << i << ' ';
		s.substr(sa[i], s.find( '$', sa[i])-sa[i]) << endl;
    }
}

//returns (lowerbound, upperbound) of the search
pii stringMatching(string P){ //O(si(P)lgn)
	int lo=0, hi=n-1, mid=lo;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res=s.compare(sa[mid], si(P), P);
		if(res>=0) hi=mid;
		else lo=mid+1;
	}
	if(s.compare(sa[lo], si(P), P)!=0) return pii(-1, -1);
	pii ans; ans.first=lo;
	lo=0, hi=n-1, mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res=s.compare(sa[mid], si(P), P);
		if(res>0) hi=mid;
		else lo=mid+1;
	}
	if(s.compare(sa[hi], si(P), P)!=0) hi--;
	ans.second=hi;
	return ans;
}

//Calculates the LCP between consecutives suffixes in the Suffix Array.
//LCP[i] is the length of the LCP between sa[i] and sa[i-1]
int LCP[MAXN], phi[MAXN], PLCP[MAXN];
void computeLCP(){//O(n)
	phi[sa[0]]=-1;
	forsn(i,1,n) phi[sa[i]]=sa[i-1];
	int L=0;
	forn(i,n){
		if (phi[i]==-1) {PLCP[i]=0; continue;}
		while (s[i+L]==s[phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1, 0);
	}
	forn(i,n) LCP[i]=PLCP[sa[i]];
}
