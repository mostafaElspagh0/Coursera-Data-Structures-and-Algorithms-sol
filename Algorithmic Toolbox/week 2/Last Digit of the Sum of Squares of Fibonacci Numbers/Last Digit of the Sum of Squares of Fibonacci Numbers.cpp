#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=1, b=0,n,c;
    int i;
    cin>>n;
    n%=60;
    for(i = 0 ; i <= n ; i++){
        c = a;
        a = b ;
        b += c;
        a%=10;
        b%=10;
    }
    cout<<(a*b)%10;
}
