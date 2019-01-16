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

const int N = 100+10;
int c, v, target, choice[N][N], pos[N][N];

struct configuration {
    int remaining, visible[N], last[N], // visible: delante de target
        front[N], first[N]; // front: al principio 
    bool taken[N]; 

    configuration() {}

    configuration(configuration &conf) {
        remaining = conf.remaining;
        forn(i, v) {
            last[i] = conf.last[i];
            first[i] = conf.first[i];
        }
        forn(j, c) {
            taken[j] = conf.taken[j]; 
            visible[j] = conf.visible[j];
            front[j] = conf.front[j];
        }
    }

    void init() {
        remaining = c;
        forn(j, c) {
            taken[j] = true; 
            visible[j] = v;
            front[j] = 0;
        }
        forn(i, v) {
            last[i] = c-1;
            first[i] = 0;
            front[choice[i][0]]++;
        }
    }

    void mark(int cand) {
        taken[cand] = false;
    }

    void remove(int cand) {
        remaining--;
        mark(cand);

        forn(i, v) {
            int &j = first[i];
            while (j < c && !taken[choice[i][j]]) {
                j++;
                if (j < c) front[choice[i][j]]++;
            }
        }
    }

    void put(int cand) {
        mark(cand);

        forn(i, v) {
            int &j = last[i];
            while (pos[i][cand] < j) {
                visible[choice[i][j]]--;
                j--;
            }
        }
    }

    bool can() {
        if (!taken[target]) return true;

        put(target);
        remaining--;

        forn(_, remaining) {
            int next = -1;
            forn(j, c) if (taken[j] && 2*visible[j] < v) { next = j; break; }

            if (next == -1) return false;
            put(next);
        }

        return true;
    }
};



string tempChoice[N][N], tempTarget, sortedCands[N];
int h(string s) {
    return lower_bound(sortedCands, sortedCands + c, s) - sortedCands;
}

int main() {
	fastio;
	
    cin >> c >> v;
    forn(i, v) forn(j, c) cin >> tempChoice[i][j];
    cin >> tempTarget;

    // map to numbers
    forn(j, c) sortedCands[j] = tempChoice[0][j];
    sort(sortedCands, sortedCands + c);
    forn(i, v) forn(j, c) { 
        choice[i][j] = h(tempChoice[i][j]);
        pos[i][choice[i][j]] = j;
    }
    target = h(tempTarget);

    // init
    configuration conf, temp;
    conf.init();

    // impossible?
    temp = conf;
    if (!conf.can()) { cout << '*' << endl; return 0; }
    conf = temp;

    // try and check
    forn(i, c) {
        temp = conf;

        int next;
        forn(cand, c) {
            if (conf.taken[cand]
                && (cand != target || 2*conf.front[target] > v)) {
                conf.remove(cand);
                if (conf.can()) { next = cand; break; }
                conf = temp;
            }
        }

        conf = temp;
        conf.remove(next);
        cout << sortedCands[next] << " \n"[i == c-1];
    }
	
	return 0;
}
