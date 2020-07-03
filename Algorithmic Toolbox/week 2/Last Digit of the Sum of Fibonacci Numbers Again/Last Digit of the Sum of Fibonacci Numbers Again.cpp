#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=1, b=0,l , r,c, ans;
    int i;
    cin>>l>>r;
    l %= 60;
    r %= 60;
    if ( r<= l){
        r+=60;
    }
    ans = 0;
    for(i = 0 ; i <= r ; i++){
        if(i >= l){
           ans += b;
           ans %= 10;
        }
        c = a;
        a = b ;
        b += c;
    }
    cout<<ans;
}
