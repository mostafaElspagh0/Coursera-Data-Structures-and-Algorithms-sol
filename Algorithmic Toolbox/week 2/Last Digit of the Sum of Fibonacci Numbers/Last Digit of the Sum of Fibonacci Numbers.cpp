#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=1, b=0,c, n;
    cin>>n;
    n %= 60;
    long long ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        c = a;
        a = b ;
        b += c;
        a %= 10;
        b %= 10;
        ans += b;
        ans %=10;
    }
    cout<<ans<<endl;
}
