#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void countPost(vector<vector<int>> &adj, vector<bool> &visited, int &cont, vector<int> &postVals, int x){
  if(!visited[x]){
    visited[x] = true;
    cont += 1;
    for(int i = 0; i < adj[x].size(); i++){
      countPost(adj, visited, cont, postVals, adj[x][i]);
    }
    cont += 1;
    postVals[x] = cont;
  }
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int x){
  if(!visited[x]){
    visited[x] = true;
    for(int i = 0; i < adj[x].size(); i++){
      dfs(adj, visited, adj[x][i]);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int> > &adj, vector<vector<int> > &inv) {
  int cont = 0;
  vector<bool> visited(inv.size());
  vector<int> postVals(inv.size());

  for(int i = 0; i < inv.size(); i++){
    countPost(inv, visited, cont, postVals, i);
  }

  sort(postVals.begin(), postVals.end());
  
  visited.clear();
  int result = 0;
  
  for(int i = postVals.size()-1; i >= 0; i--){
    if(!visited[postVals[i]]){
      dfs(adj, visited, postVals[i]);
      result++;
    }
  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > inv(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    inv[y-1].push_back(x-1);
  }
  std::cout << number_of_strongly_connected_components(adj, inv);
}
