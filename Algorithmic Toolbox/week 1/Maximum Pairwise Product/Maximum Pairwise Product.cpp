#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, max1, max2, t;
    scanf("%ld %ld %ld", &n, &max1, &max2);
    if(max2>max1){
        swap(max1,max2);
    }
    n -= 2;
    while(n--){
      scanf("%ld",&t);
      if(t>= max1){
        max2 = max1;
        max1 = t;
      }else if(t>max2){
        max2 = t;
      }
    }
    printf("%lld",max1*max2);
}
