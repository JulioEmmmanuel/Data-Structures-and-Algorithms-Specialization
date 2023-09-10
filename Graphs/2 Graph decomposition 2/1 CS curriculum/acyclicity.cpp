#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited(1005);
vector<bool> stack(1005);

bool check_cycle(vector<bool> &stack, vector<vector<int> > &adj, int x)
{
  if(stack[x]){
    return true;
  }

  if(visited[x]){
    return false;
  }

  visited[x] = true;
  stack[x] = true;

  bool res = false;
  for(int i = 0; i < adj[x].size(); i++){
    res = res | check_cycle(stack, adj, adj[x][i]);
  }

  stack[x] = false;

  return res;
}


bool acyclic(vector<vector<int> > &adj) {
  //write your code here
  bool res = false;
  for(int i = 0; i < adj.size(); i++){
    if(!visited[i]){
      res = res | check_cycle(stack, adj, i);
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
