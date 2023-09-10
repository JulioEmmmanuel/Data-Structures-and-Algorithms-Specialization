#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

class DisjointSet {
  public:
    DisjointSet(int n){
      for(int i = 0; i < n; i++){
        set.push_back(-1);
      }
    }

    int find(int n){
      if(set[n] < 0){
        return n;
      }
      set[n] = find(set[n]);
    }

    void unite(int a, int b){
      int rootA = find(a);
      int rootB = find(b);
      if(set[rootA] < set[rootB]){
        set[rootA] += set[rootB];
        set[rootB] = rootA;
      } else {
        set[rootB] += set[rootA];
        set[rootA] = rootB;
      }
    }

  private:
    vector<int> set;
};


struct edge {
 int from = 0;
 int to = 0;
 double cost = 0; 
};

bool compareByCost(edge e1, edge e2){
  return e1.cost < e2.cost;
}

double distance(int x1, int x2, int y1, int y2){
  return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

double clustering(vector<int> x, vector<int> y, int k) {
  int n = x.size();
  vector<edge> edges;

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      edge e;
      e.from = i;
      e.to = j;
      e.cost = distance(x[i], x[j], y[i], y[j]);
      edges.push_back(e);
    }
  }

  sort(edges.begin(), edges.end(), compareByCost);
  DisjointSet ds(n);

  int cont = n;

  for(edge e: edges){
    if(ds.find(e.from) != ds.find(e.to)){
      ds.unite(e.from, e.to);
      cont--;
      if(cont == k-1){
        return e.cost;
      }
    }
  }

  
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
