const double EPS = 1e-9;
#define less(a,b)          ((a) < (b) - EPS)
#define greater(a,b)       ((a) > (b) + EPS)
#define less_equal(a,b)    ((a) < (b) + EPS)
#define greater_equal(a,b) ((a) > (b) - EPS)
#define equal(a,b)         (abs((a) - (b)) < EPS)
