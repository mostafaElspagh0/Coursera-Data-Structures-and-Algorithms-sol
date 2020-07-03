#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b,c;
    cin>>a>>b;
    if(b > a){
        swap(a,b);
    }
    while(b != 0){
        c = b ;
        b = a % b ;
        a = c;
    }
    cout<<a<<endl;
}
