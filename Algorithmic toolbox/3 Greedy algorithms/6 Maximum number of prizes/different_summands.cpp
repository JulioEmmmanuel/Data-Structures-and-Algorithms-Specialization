#include <iostream>
#include <vector>

using std::vector;

vector<long long> optimal_summands(long long n) {
  vector<long long> summands;
  //write your code here
  long long current = 1;
  while(n > 0){
    if (current > n)
    {
      summands.pop_back();
      summands.push_back(n+current-1);
      break;
    }
    summands.push_back(current);
    n -= current;
    current++;
  }
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << '\n';
}
