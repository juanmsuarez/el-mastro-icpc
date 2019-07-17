int normal(int a){ return ((a % M) + M) % M;} // Use for negative numbers (the 2nd modulo is avoidable)
int add(int a, int b){ return a+b < M ? a+b : a+b-M; }
int sub(int a, int b){ return a-b >= 0 ? a-b : a-b+M; }
int mul(int a, int b){ return int(ll(a)*b % M); }
int div(int a, int b) { return mul(a, inv(b)); }
int neg(int a){ return add(-a, M); }
