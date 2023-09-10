#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
int nums[1000005];

vector<int> optimal_sequence(int n) {
  nums[1] = 1;
  for(int i = 2; i <= n; i++){
    int o1 = nums[i-1] + 1;
    int o2 = std::numeric_limits<int>::max();
    int o3 = std::numeric_limits<int>::max();
    if(i % 2 == 0){
      o2 = nums[i/2] + 1;
    }
    if(i % 3 == 0){
      o3 = nums[i/3] + 1;
    }
    nums[i] = std::min(o1, std::min(o2, o3));
  }


  std::vector<int> sequence;
  int i = n;
  int current = nums[i];

  while (i > 1) {
    sequence.push_back(i);
    if(nums[i-1] == current-1){
      i--;
    } else if(i % 2 == 0 && nums[i/2] == current-1){
      i/=2;
    } else {
      i/=3;
    }
    current--;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout << '\n';
}
