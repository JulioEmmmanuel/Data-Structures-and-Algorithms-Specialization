#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using std::vector;
using std::priority_queue;
using std::numeric_limits;
using std::pair;
using std::make_pair;

struct edge {
 int idx = 0;
 double cost = 0; 
};

class Compare {
  public:
    bool operator()(pair<int, double> p1, pair<int, double> p2){
      return p1.second > p2.second;
    }
};

double distance(int x1, int x2, int y1, int y2){
  return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int n = x.size();
  vector<vector<edge>> adj(n, vector<edge>());

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      edge e1, e2;
      e1.idx = j;
      e1.cost = distance(x[i], x[j], y[i], y[j]);
      adj[i].push_back(e1);
      e2.idx = i;
      e2.cost = e1.cost;
      adj[j].push_back(e2);
    }
  }

  vector<bool> visited(n, false);
  vector<double> value(n, numeric_limits<double>::max());
  priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;
  value[0] = 0;
  pq.push(make_pair(0, 0));

  while(!pq.empty()){
    pair<int, double> p = pq.top();
    pq.pop();
    int u = p.first;

    if(visited[u]){
      continue;
    }

    result += p.second;
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i].idx;
      double cost = adj[u][i].cost;
      if(value[v] > cost){
        value[v] = cost;
        pq.push(make_pair(v, value[v]));
      }
    }

  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
