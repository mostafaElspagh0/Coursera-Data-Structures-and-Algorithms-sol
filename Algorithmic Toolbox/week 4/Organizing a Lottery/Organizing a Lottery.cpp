#include <bits/stdc++.h>

using namespace std;

int main() {
  int num_line_segmants, num_points, temp, temp2;
  scanf("%d %d", &num_line_segmants, &num_points);
  vector<int> points;
  vector<pair<int, int>> segmants;
  vector<int> queries;

  for (int i = 0; i < num_line_segmants; i++) {
    scanf("%d %d", &temp, &temp2);
    segmants.push_back({temp, temp2});
    points.push_back(temp2);
    points.push_back(temp);
  }
  for (int i = 0; i < num_points; i++) {
    scanf("%d", &temp);
    queries.push_back(temp);
    points.push_back(temp);
  }
  sort(points.begin(), points.end());
  map<int, int> value_index;
  for (int i = 0; i < points.size(); i++) {
    value_index[points[i]] = i;
  }

  vector<int> cumArr(points.size() * 2, 0);
  for (pair<int, int> p : segmants) {
    cumArr[value_index[p.first]] += 1;
    cumArr[value_index[p.second] + 1] -= 1;
  }
  for (int i = 1; i < cumArr.size(); i++) {
    cumArr[i] += cumArr[i - 1];
  }
  for (int i : queries) {
    printf("%d ", cumArr[value_index[i]]);
  }
}