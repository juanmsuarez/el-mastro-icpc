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
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct card {
    int rank, suit;
    
    card(int rank = 0, int suit = 0) : rank(rank), suit(suit) {}    

    bool operator < (const card &o) const {
        return  rank < o.rank || (rank == o.rank && suit < o.suit);
    }
    bool operator == (const card &o) const {
        return rank == o.rank && suit == o.suit;
    }

    inline int number() {
        return rank*4 + suit;
    }
};

vector<char> ranks = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'},
    suits = {'C', 'D', 'H', 'S'};
int myRank[100], mySuit[100];

int cantOfSuit[4];
bool hasSuit[4], exists[60], selected[60], seenItAll[4];
int seenSuit[4];
vector<card> cs;
int size;

// THIS TL!
bool go();

bool select() {
	bool finish = true;
    //for (card c : cs) cerr << ranks[c.rank] << suits[c.suit] << ' ';
    //cerr << endl;
	card last = cs.back();

    forn(i, 4) if (hasSuit[i] && !(seenItAll[i] || seenSuit[i] == cantOfSuit[i] || last.suit == i)) finish = false;

    if (finish) return true;
    else if (size > 7) return false;
    // selecciono carta nuevo suit
    forn(s, 4)
        if (last.suit != s) {
            card c = {last.rank, s};
			int num = c.number();
            if (!selected[num] && exists[num]) {
				selected[num] = true;
				seenSuit[c.suit]++;
                cs.pb(c);

				size++;

                if (go())
                    return true;

				size--;

				selected[num] = false;
				seenSuit[c.suit]--;
                cs.pop_back();
            }
        }

    return false;
}

bool go() {
    bool finish = true;
	card last = cs.back();
    // THIS TL!
    //for (card c : cs) cerr << ranks[c.rank] << suits[c.suit] << ' ';
    //cerr << endl;
    forn(i, 4) if (hasSuit[i] && !(seenItAll[i] || seenSuit[i] == cantOfSuit[i] || last.suit == i)) finish = false;

    if (finish) return true;
    else if (size > 7) return false;

    // selecciono carta salida en este suit
    forn(r, 13) {
        //cerr << "creo1 " << ranks[r] << ' ' << suits[last.suit] << endl;
        card c = {r, last.suit};
		int num = c.number();
        if ((selected[c.number()] && !(c == last)) || !exists[c.number()]) continue;
        //cerr << "y agrego" << endl;

        bool nuevo = !selected[num], nuevoRank = r != last.rank, nuevoAll = !seenItAll[c.suit] && !(c == last);
		if (nuevoAll)
			seenItAll[c.suit] = true;
        if (nuevoRank)
            cs.pb(c);
        if (nuevo) {
			seenSuit[c.suit]++;
			selected[num] = true;
		}
		size++;

        if (select())
            return true;

		size--;
		if (nuevoAll)
			seenItAll[c.suit] = false;
        if (nuevoRank)
            cs.pop_back();
        if (nuevo) {
			seenSuit[c.suit]--;
			selected[num] = false;
		}
    } 

    return false;
}

int main() {
    fastio;

    //freopen("rin.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	
	forn(s, 4) mySuit[suits[s]] = s;
	forn(r, 13) myRank[ranks[r]] = r;

    int n;

    while (cin >> n) {
        fill(exists, exists+60, false);
        fill(hasSuit, hasSuit+4, false);
        fill(cantOfSuit, cantOfSuit+4, 0);
        fill(seenSuit, seenSuit+4, 0);
        fill(seenItAll, seenItAll+4, false);
        fill(selected, selected+60, false);

		vector<card> allCards;

        forn(_, n) {
            char rank, suit;
            cin >> rank >> suit;

            card c = {myRank[rank], mySuit[suit]};
			allCards.pb(c);

            hasSuit[c.suit] = true;
            cantOfSuit[c.suit]++;
            exists[c.number()] = true;
        }

        bool can = false;

		for (card c : allCards) {
			cs = vector<card>();

			cs.pb(c);
			selected[c.number()] = true;
			seenItAll[c.suit] = true;
			size = 1;

			if (select()) {
				can = true;
				break;
			}

			selected[c.number()] = false;
			seenItAll[c.suit] = false;
		}

        cout << (can?"YES":"NO") << endl;
    }

    return 0;
}
