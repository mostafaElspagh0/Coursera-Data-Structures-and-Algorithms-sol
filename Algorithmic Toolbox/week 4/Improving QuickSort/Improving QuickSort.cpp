#include <bits/stdc++.h>
using namespace std;
void partition(vector<int> &arr, int low, int high, int &i, int &j) {
  if (high - low <= 1) {
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    i = low;
    j = high;
    return;
  }
  int mid = low;
  int pivot = arr[high];
  while (mid <= high) {
    if (arr[mid] < pivot)
      swap(arr[low++], arr[mid++]);
    else if (arr[mid] == pivot)
      mid++;
    else if (arr[mid] > pivot)
      swap(arr[mid], arr[high--]);
  }
  i = low - 1;
  j = mid;
}

void quicksort(vector<int> &arr, int low, int high) {
  if (low >= high) return;
  int i, j;
  partition(arr, low, high, i, j);
  quicksort(arr, low, i);
  quicksort(arr, j, high);
}

int main() {
  int arr_len, temp;
  vector<int> arr;
  scanf("%d", &arr_len);
  for (int i = 0; i < arr_len; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  quicksort(arr, 0, arr_len - 1);
  for (int i : arr) {
    printf("%d ", i);
  }
  return 0;
}
