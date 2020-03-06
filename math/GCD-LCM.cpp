// Predefined in C++17: gcd(a, b)
template<class T> T gcd(T a, T b) { return b ? __gcd(a,b) : a; }
// Predefined in C++17: lcm(a, b)
template<class T> T lcm(T a, T b) { return a * (b / gcd(a,b)); }
