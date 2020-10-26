#include<bits/stdc++.h>
using namespace std;

void toposortUtil(vector<vector<int>> &adj, vector<int> &used,
                  vector<int> &order, int x) {
  used[x] = true;
  for (const int i : adj[x])
    if (!used[i]) toposortUtil(adj, used, order, i);
  order.push_back(x);
}

vector<int> toposort(vector<vector<int>> &adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  for (int i = 0; i < adj.size(); i++)
    if (!used[i]) toposortUtil(adj, used, order, i);
  reverse(order.begin(), order.end());
  return order;
}

void reverseGraph(vector<vector<int>> &adj, vector<vector<int>> &adjRet) {
  for (int i = 0; i < adj.size(); i++) {
    for (const int j : adj[i]) {
      adjRet[j].push_back(i);
    }
  }
}

void dfsUtil(vector<bool> &vis, vector<vector<int>> &adj, int node) {
  vis[node] = true;
  for (int i : adj[node]) {
    if (!vis[i]) {
      dfsUtil(vis, adj, i);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int>> adj) {
  int result = 0;
  vector<int> topologicalSort = toposort(adj);
  vector<vector<int>> reversedGraph(adj.size(),vector<int>());
  reverseGraph(adj, reversedGraph);
  vector<bool> vis(reversedGraph.size(), false);
  for (int i : topologicalSort) {
    if (!vis[i]) {
      result += 1;
      dfsUtil(vis, reversedGraph, i);
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
