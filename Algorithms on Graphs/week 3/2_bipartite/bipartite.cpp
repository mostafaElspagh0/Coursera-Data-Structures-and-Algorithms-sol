#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

bool bipartiteUtil(vector<vector<int>> &adj, vector<int> &color,
                   vector<bool> &vis, int s) {
  if (vis[s]) return true;
  vis[s] = true;
  color[s] = 0;
  queue<int> q;
  q.push(s);
  int node;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    for (const int i : adj[node]) {
      if (color[node] == color[i]) return false;
      if (!vis[i]) {
        color[i] = (color[node] + 1) % 2;
        q.push(i);
        vis[i] = true;
      }
    }
  }
  return true;
}

int bipartite(vector<vector<int>> &adj) {
  vector<int> color(adj.size(), -1);
  vector<bool> vis(adj.size(), false);
  for (int i = 0; i < adj.size(); i++)
    if (!bipartiteUtil(adj, color, vis, i)) return false;
  return true;
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
  std::cout << bipartite(adj);
}
