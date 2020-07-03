#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=1, b=0,c, n, m;
    cin>>n>>m;
    int i;
    for(i = 0 ; i < m*m ; i++){
        c = a;
        a = b ;
        b += c;
        a%=m;
        b%=m;
        if(a == 0 && b == 1 && i != 0){
            break;
        }
    }
    n %= i ;
    a=1, b=0;
    for(i = 0 ; i < n ; i++){
        c = a;
        a = b ;
        b += c;
        a%=m;
        b%=m;
    }
    cout<<b<<endl;
}
