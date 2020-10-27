#include <bits/stdc++.h>
using namespace std;

void bipartiteUtil(vector<vector<int>> &adj, vector<int> &levels, vector<bool> &vis , int s) {
  vis[s] = true;
  levels[s] = 0;
  queue<int> q;
  q.push(s);
  int node;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    for (const int i : adj[node]) {
      if (!vis[i]) {
        levels[i] = levels[node] + 1;
        q.push(i);
        vis[i] = true;
      }
    }
  }
}

int distance(vector<vector<int>> &adj, int s, int t) {
  vector<int> levels(adj.size() , -1);
  vector<bool> vis(adj.size(), false);
  bipartiteUtil(adj, levels, vis , s);
  return levels[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
