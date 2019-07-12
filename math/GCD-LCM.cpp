template<class T> T gcd(T a,T b){return b?__gcd(a,b):a;}
//en C++17 gcd(a,b) predefinido
template<class T> T lcm(T a,T b){return a*(b/gcd(a,b));}
//en C++17 lcm(a,b) predefinido
