#include<bits/stdc++.h>

using namespace std ;

int main(){
    int arr_len, temp ;
    vector<int> arr;
    scanf("%d",&arr_len);
    for(int i = 0 ; i < arr_len ; i++){
        scanf("%d",&temp);
        arr.push_back(temp);
    }
    int majIndex = 0 , count = 1;
    for(int i = 1 ; i < arr_len; i++){
        if(arr[majIndex] == arr[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
            majIndex = i ;
            count = 1;
        }
    }
    count  = 0 ;
    for(int i = 0 ; i < arr_len ; i++){
        if(arr[majIndex] == arr[i]){
            count++;
        }
        if(count > (arr_len/2)){
            printf("1");
            return 0 ;
        }
    }
    printf("0");
    return 0 ;
}