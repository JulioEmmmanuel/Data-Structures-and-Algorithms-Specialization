#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::numeric_limits;


class Compare{
  public:
    bool operator() (pair<int, long long> a, pair<int, long long> b){
      return a.second > b.second;
    }
};

long long distance(vector<vector<int> > &adj, vector<vector<long long> > &cost, int s, int t) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  vector<long long> distances(adj.size(), numeric_limits<long long>::max());
  distances[s] = 0;
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, Compare> pq;
  pq.push(make_pair(s, 0));

  while(!pq.empty()){
    int u = pq.top().first;
    pq.pop();

    if(!visited[u]){
      visited[u] = true;
    } else {
      continue;
    }

    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      long long c = cost[u][i];
      if(distances[v] > distances[u] + c){
        distances[v] = distances[u] + c;
        pq.push(make_pair(v, distances[v]));
      }
    }
  }

  if(distances[t] == numeric_limits<long long>::max()){
    return -1;
  } else {
    return distances[t];
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<long long> > cost(n, vector<long long>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
