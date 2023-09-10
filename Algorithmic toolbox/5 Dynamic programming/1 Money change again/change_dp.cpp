#include <iostream>

int change[1005];

int get_change(int m) {
  //write your code here
  change[1] = 1;
  change[2] = 2;
  change[3] = 1;
  change[4] = 1;
  for(int i = 5; i <= m; i++){
    int o1 = change[i-1] + 1;
    int o2 = change[i-3] + 1;
    int o3 = change[i-4] + 1;
    change[i] = std::min(o1, std::min(o2, o3));
  }
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
