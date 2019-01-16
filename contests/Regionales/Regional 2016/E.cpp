#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#ifdef LOCAL
#define DBG(a) cerr << #a << "=" << a << endl
#define RAYA cerr << "----------" << endl
#else
#define DBG(a)
#define RAYA
#define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int NEUTRO = 0, MAXN = 1e5+10, MAXM = 4e6+10;

struct node {
    int l, r, ind;
    int left, right;
    int val;

    node() {}

    int init(int _l, int _r, int _ind, int _left, int _right);

    int upd(int p);
};

int cant;
node nodos[MAXM];
int seq[MAXN], inds[MAXN], st[MAXN], sorted[MAXN];

int getNew(int l, int r, int left = 0, int right = 0) {
    cant++;
    return nodos[cant].init(l, r, cant, left, right);
}

int node::init(int _l, int _r, int _ind, int _left, int _right) {
    l = _l;
    r = _r;
    ind = _ind;
    val = NEUTRO;

    if (l+1 < r) {
        left = _left == 0 ? getNew(l, (l+r)/2) : _left;
        right = _right == 0 ? getNew((l+r)/2, r) : _right;
    }
    else 
        left = right = 0;

    return ind;
}

int node::upd(int p) {
    if (p<l || r<=p) return ind;

    int resInd;

    if (l+1==r) { 
        resInd = getNew(l, r);
        nodos[resInd].val = val+1;
        return resInd;
    }

    resInd = getNew(l, r, nodos[left].upd(p), nodos[right].upd(p));

    int indLeft = nodos[resInd].left, indRight = nodos[resInd].right;
    nodos[resInd].val = nodos[indLeft].val + nodos[indRight].val;

    return resInd;
}

int query(int l, int r, int k) {
    if (nodos[l].l+1 == nodos[l].r) return nodos[l].l;

    int indLeft = nodos[l].left, indRight = nodos[r].left;
    if (nodos[indRight].val - nodos[indLeft].val >= k)
        return query(indLeft, indRight, k);
    else 
        return query(nodos[l].right, nodos[r].right, k - (nodos[indRight].val - nodos[indLeft].val));
}

int main() {
    fastio;

#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("err.txt","w",stderr);
#endif
    int n,m;

    while(cin >> n >> m){
        cant = 0;

        forn(i,n) {
            cin >> seq[i];
            sorted[i] = seq[i];
        }

        sort(sorted, sorted+n);
        int sz = unique(sorted, sorted+n)-sorted;

        forn(i, n)
            inds[i]=lower_bound(sorted, sorted+sz, seq[i])-sorted;

        st[0] = getNew(0, n);
        forn(i,n)
            st[i+1]=nodos[st[i]].upd(inds[i]);
        forn(i,m){
            char q;
            cin >> q;
            if(q=='S'){ 
                int w;
                cin >> w;
                st[w]=nodos[st[w-1]].upd(inds[w]);
                swap(inds[w], inds[w-1]);
            }
            else{
                int l,r,k;
                cin >> l >> r>> k;
                cout << sorted[query(st[l-1],st[r],k)] << endl;
            }
        }
    }

    return 0;
}

