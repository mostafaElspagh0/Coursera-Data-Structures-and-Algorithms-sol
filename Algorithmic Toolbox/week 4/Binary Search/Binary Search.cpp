#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr_len, temp, qn;
  scanf("%d", &arr_len);
  vector<int> arr;
  for (int i = 0; i < arr_len; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  scanf("%d", &qn);
  while (qn--) {
    scanf("%d", &temp);
    int low = 0, high = arr_len - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] == temp) {
        break;
      } else if (arr[mid] > temp) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (arr[mid] == temp) {
      printf("%d ", mid);
    } else {
      printf("-1 ");
    }
  }
}