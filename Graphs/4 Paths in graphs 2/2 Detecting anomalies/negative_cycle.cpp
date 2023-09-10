#include <iostream>
#include <vector>
#include <limits>

using std::vector;
using std::numeric_limits;

bool negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, vector<int> &dist, vector<bool> &visited, int source) {
  //write your code here
    //Initialize distances as INFINITE and 0 for the source
    for(int i = 0; i < adj.size(); i++){
      dist[i] = numeric_limits<int>::max();
    }
    dist[source] = 0;
    visited[source] = true;

    //Relax all edges |V-1| times
    for(int k = 0; k < adj.size()-1; k++){
      for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++){
          int u = i;
          int v = adj[i][j];
          int weight = cost[i][j];
          if(dist[u] == numeric_limits<int>::max()){
            continue;
          } else if(dist[v] > dist[u] + weight){
            dist[v] = dist[u] + weight;
            visited[v] = true;
          }
        }
      }
    }

    //Relax all edges one more time
    for(int i = 0; i < adj.size(); i++){
      for(int j = 0; j < adj[i].size(); j++){
        int u = i;
        int v = adj[i][j];
        int weight = cost[i][j];
        if(dist[u] == numeric_limits<int>::max()){
            continue;
          }
        if(dist[v] > dist[u] + weight){
          dist[v] = dist[u] + weight;
          return true;
        }
      }
    }

    return false;
}

bool check_for_negative_cycles(vector<vector<int> > &adj, vector<vector<int> > &cost){
    vector<int> dist(adj.size());
    vector<bool> visited(adj.size(), false);
    for(int i = 0; i < adj.size(); i++){
      if(!visited[i]){
        if(negative_cycle(adj, cost, dist, visited, i)){
          return true;
        }
      }
    }

    return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << check_for_negative_cycles(adj, cost);
}
