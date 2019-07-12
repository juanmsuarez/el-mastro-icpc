
#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s, n) for (int i = (int)s; i < (int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define dforsn(i,s, n) for (int i = (int)(n-1); i >= (int)(s); i--)

#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

deque<int> act;
int d;
int sum;

void inc(){
    act[d-1]++;
    dforsn(i,1,si(act)){
        if(act[i]==10){
            act[i]=0;
            act[i-1]++;
            sum-=9;
        }
    }
    if(act[0]==10){
        act[0]=0;
        d++;
        sum-=9;
        act.push_front(1);
    }
    sum++;

}

void printnum(){
    for(int a:act)cout << a;
    cout << endl; 
}

int main() {
    int n;
    cin >> n;
    vi b(n);
    for(int &a:b)cin >> a;

    d=0;
    sum=0;
    
    while(sum < b.front()){
        act.push_front(min(9,b.front()-sum));
        sum+=act.front();
        d++;
    }
    printnum();
    

    forsn(k,1,n){
        inc();
        //printnum();
        int target = b[k];
        if(sum < target){
            if(d*9< target){
                d = 0;
                act = deque<int>();
                sum=0;
                while(sum < target){
                    act.push_front(min(9,target-sum));
                    sum+=act.front();
                    d++; 
                }
            }
            else{
                for(int i = si(act)-1;i>=0&&sum<target;i--){
                    int dig = act[i];
                    act[i]+=min(9-dig,target-sum);
                    sum+=act[i]-dig;
                } 
            }
        }
        else if(sum > target){
            int rem = 0;
            dforsn(i,0,d){
                //cerr << "R " << rem << endl;
                if(act[i]<9 && (sum+1-rem <=target)){
                    sum-=rem;
                    for(int j = si(act)-1;j>i&&sum<b[j];j--){
                        int dig = act[j];
                        act[j]+=min(9-dig,target-sum);
                        sum+=act[j]-dig;
                    } 
                    act[i]++;

                    break;

                }
                else rem+=act[i];
            }
            if(sum!=target){
                d++;
                act = deque<int>(d,0);
                act[0]=1;
                sum=1;
                int ind = d-1;
                while(sum < target){
                    act[ind]=(min(9,target-sum));
                    sum+=act[ind];
                    ind--;
                }


            }


        }
        printnum();

    }

}
