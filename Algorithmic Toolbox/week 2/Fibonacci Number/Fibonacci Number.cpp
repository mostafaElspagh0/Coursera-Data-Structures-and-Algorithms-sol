#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a=1, b=0,c, n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        c = a;
        a = b ;
        b += c;
    }
    cout<<b<<endl;
}
