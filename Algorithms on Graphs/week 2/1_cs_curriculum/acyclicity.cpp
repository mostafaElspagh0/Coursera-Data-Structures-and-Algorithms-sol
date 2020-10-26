#include <bits/stdc++.h>
using namespace std;

bool acyclicUtil(vector<vector<int>> &adj, set<int> callStack,
                  vector<bool> &vis, int currNode) {
  vis[currNode] = true;
  for (const int node : adj[currNode]) {
    if (vis[node] && callStack.count(node)) return false;
    if (!vis[node]) {
      callStack.insert(node);
      if (!acyclicUtil(adj, callStack, vis, node)) return false;
      callStack.erase(node);
    }
  }
  return true;
}


int acyclic(vector<vector<int>> &adj) {
  vector<bool> vis(adj.size(), false);
  set<int> callStack;
  for (int i = 0; i < adj.size(); i++) {
    callStack.insert(i);
    if (!vis[i] && !acyclicUtil(adj, callStack, vis, i)) {
      return 1;
    }
    callStack.clear();
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
