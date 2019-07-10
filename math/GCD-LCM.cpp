template<class T> T gcd(T a,T b){return b?__gcd(a,b):a;}
// gcd(a,b) predefinido en C++17 STL
template<class T> T lcm(T a,T b){return a*(b/gcd(a,b));}
// lcm(a,b) predefinido en C++17 STL
