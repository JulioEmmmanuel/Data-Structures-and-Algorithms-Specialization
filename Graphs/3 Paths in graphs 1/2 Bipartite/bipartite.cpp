#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size());
  vector<int> colors(adj.size(), -1);
  queue<int> processed;

  for(int i = 0; i < adj.size(); i++){
    if(!visited[i]){

        visited[i] = true;
        colors[i] = 0;
        processed.push(i);

        while(!processed.empty()){
          
          int x = processed.front();
          processed.pop();
          
          for(int i = 0; i < adj[x].size(); i++){
            int neigh = adj[x][i];
            int nextColor = colors[x] == 0 ? 1 : 0;
            if(colors[neigh] != -1 && colors[neigh] != nextColor){
              return false;
            }

            if(!visited[neigh]){
              processed.push(neigh);
              colors[neigh] = nextColor;
              visited[neigh] = true;
            }
          }

        }

    }
  }

  return 1;
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
  std::cout << bipartite(adj);
}
