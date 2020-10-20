#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, u, v;
vector<int> graph[1003];
int vis[1003];
int ans = 0;
void dfs(int node) {
  vis[node] = true;
  if (v == node) {
    ans = 1;
    return;
  }
  for (int i : graph[node]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
 
  scanf("%d %d", &u, &v);
   dfs(u);
  printf("%d", ans);
}
