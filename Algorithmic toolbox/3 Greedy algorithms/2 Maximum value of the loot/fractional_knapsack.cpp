#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  for (int i = 0; i < weights.size(); i++){

    if(capacity <= 0){
      return value;
    }

    double maxUnitWeight = 0.0;
    int indexMax = 0;
    for (int j = 0; j < weights.size(); j++)
    {
      if(values[j]/(double)weights[j] > maxUnitWeight){
        maxUnitWeight = values[j] / (double)weights[j];
        indexMax = j;
      }
    }
    int quantity = std::min(capacity, weights[indexMax]);
    value += maxUnitWeight * quantity;
    capacity -= quantity;
    weights.erase(weights.begin() + indexMax);
    values.erase(values.begin() + indexMax);
  }

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
