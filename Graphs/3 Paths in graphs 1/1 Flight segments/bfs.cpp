#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> visited(adj.size());
  vector<int> d(adj.size(), -1);
  queue<int> processed;

  processed.push(s);
  visited[s] = true;
  d[s] = 0;

  while(!processed.empty()){
    int x = processed.front();
    processed.pop();
    for(int i = 0; i < adj[x].size(); i++){
      int neigh = adj[x][i];
      if(!visited[neigh]){
        processed.push(neigh);
        d[neigh] = d[x]+1;
        visited[neigh] = true;
      }
    }
  }

  return d[t];

}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
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
