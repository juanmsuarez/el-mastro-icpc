#pragma GCC optimize ("O3")//("avx,avx2,fma") 

Random numbers: 
mt19937_64 rng(time(0)); //if TLE use 32 bits: mt19937
ll rnd(ll a, ll b) { return a + rng()%(b-a+1); }
getline(cin,str);
// Make an extra call if we previously read another thing from the input stream
cout << fixed << setprecision(n);
cout << setw(n) << setfill('0');

// #include <sys/resource.h>
struct rlimit rl;
getrlimit(RLIMIT_STACK, &rl);
rl.rlim_cur = rl.rlim_max;
setrlimit(RLIMIT_STACK, &rl);

C++11:
to_string(num) // returns a string with the representation of num
stoi,stoll,stod,stold // string to int,ll,double & long double respectively

