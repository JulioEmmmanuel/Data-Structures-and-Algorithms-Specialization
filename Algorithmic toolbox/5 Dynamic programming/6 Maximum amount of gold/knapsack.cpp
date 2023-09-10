#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weights[305][10005];

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  for (int i = 0; i <= w.size(); i++){
    weights[i][0] = 0;
  }

  for (int j = 0; j <= W; j++){
    weights[0][j] = 0;
  }

  for (int i = 1; i <= w.size(); i++){
    for (int j = 1; j <= W; j++){
      if(j >= w[i-1]){
        weights[i][j] = max(weights[i - 1][j], weights[i-1][j-w[i-1]] + w[i-1]);
      }
      else
      {
        weights[i][j] = weights[i - 1][j];
      }
    }
  }

    return weights[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
