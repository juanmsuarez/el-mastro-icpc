#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return a ? gcd(b%a,a) : b; }

int main() {
    double x; while (cin >> x) {
        x *= 100;
        auto deg = int(round(x)), round = 360*100;
        cout << round / (gcd(deg,round)) << endl;
    }
    return 0;
}
