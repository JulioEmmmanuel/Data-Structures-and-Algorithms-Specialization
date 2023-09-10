#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &shortest, int x){
  if(!visited[x]){
    visited[x] = true;
    shortest[x] = 0;
    for(int i = 0; i < adj[x].size(); i++){
      dfs(adj, visited, shortest, adj[x][i]);
    }
  }
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
    distance[s] = 0;
    reachable[s] = 1;

    vector<int> last(adj.size(), -1);
    vector<int> cycles;

    //Relax all edges |V-1| times
    for(int k = 0; k < adj.size()-1; k++){
      for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++){
          int u = i;
          int v = adj[i][j];
          int weight = cost[i][j];
          if(distance[u] == std::numeric_limits<long long>::max()){
            continue;
          } else if(distance[v] > distance[u] + weight){
            distance[v] = distance[u] + weight;
            last[v] = u;
            reachable[v] = 1;
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
        if(distance[u] == std::numeric_limits<long long>::max()){
          continue;
        } else if(distance[v] > distance[u] + weight){
          distance[v] = distance[u] + weight;
          cycles.push_back(v);
        }
      }
    }

    vector<int> cyclic;

    //Detect all vertices in cycles
    for(int i = 0; i<cycles.size(); i++){
      int x = cycles[i];
      int y = cycles[i];
      for(int i = 0; i < adj.size(); i++){
        x = last[x];
      }

      shortest[y] = 0;
      cyclic.push_back(y);
      y = last[y];
      while(y != x){
        shortest[y] = 0;
        cyclic.push_back(y);
        y = last[y];
      }
    }

    //All nodes reachable from any node in a cycle have -inf  distance
    vector<bool> visited(adj.size(), false);
    for(int i = 0; i < cyclic.size(); i++){
      dfs(adj, visited, shortest, cyclic[i]);
    }

}


int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
