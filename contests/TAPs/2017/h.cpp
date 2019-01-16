#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, aux;
    cin>>N;
    vector<int> p;
    p.push_back(0);
    for(int i=0;i<N;i++){
        cin>>aux;
        if(aux!=p[p.size()-1]) p.push_back(aux);
    }
    p.push_back(0);
    int res=0;
    for(int i=1;i<p.size()-1;i++) if(p[i]>p[i+1]&p[i]>p[i-1]) res++;
    cout<<res<<endl;
    return 0;

}
