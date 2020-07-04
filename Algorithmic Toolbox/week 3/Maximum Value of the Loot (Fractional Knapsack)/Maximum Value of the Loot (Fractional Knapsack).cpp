#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (pair<double,double> a, pair<double,double> b) {
        return ((double) a.first/a.second) < ((double) b.first / b.second);
    }
};
int main(){
    priority_queue<pair<double,double>,vector<pair<double,double>>,cmp> q;
    double n , weight , temp1 , temp2 ;
    double ans = 0 ;
    cin>>n>>weight;
    for(int i =0 ; i < n ; i++){
        cin>>temp1>>temp2;
        q.push({temp1,temp2});
    }
    while(weight > 0 && ! q.empty()){
        ans += min(q.top().second , weight) *((double) q.top().first / q.top().second);
        weight -= q.top().second;
        q.pop();
    }
    printf("%.4f",ans);
}
