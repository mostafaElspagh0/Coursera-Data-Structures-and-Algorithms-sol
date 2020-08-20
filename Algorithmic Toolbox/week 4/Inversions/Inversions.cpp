#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int low, int high, int mid) {
  int start = low, start2 = mid + 1;
  if (arr[mid] <= arr[start2]) {
    return 0;
  }
  int h = 0;
  while (start <= mid && start2 <= high) {
    if (arr[start] <= arr[start2]) {
      start++;
    } else {
      h += (mid - start + 1);
      int value = arr[start2], i = start2;
      while (i != start) {
        arr[i] = arr[i - 1];
        i -= 1;
      }
      arr[start] = value;
      start++;
      start2++;
      mid++;
    }
  }
  return h;
}

void merge_sort(vector<int> &arr, int low, int high, int &ans) {
  if (low >= high) return;
  int mid = (low + high) / 2;
  merge_sort(arr, low, mid, ans);
  merge_sort(arr, mid + 1, high, ans);
  ans += merge(arr, low, high, mid);
}

int main() {
  int arr_size, temp;
  vector<int> arr;

  scanf("%d", &arr_size);
  for (int i = 0; i < arr_size; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  int ans = 0;
  merge_sort(arr, 0, arr_size - 1, ans);
  cout << ans << endl;
  return 0;
}