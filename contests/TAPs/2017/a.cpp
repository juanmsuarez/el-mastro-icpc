#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int main() {
    string notas[12] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI"};

    int s; string n;
    cin >> s >> n;

    int ind;
    forn(i, 12) if (notas[i] == n) ind = i;

    cout << notas[(ind-s+12)%12] << endl;

    return 0;
}
