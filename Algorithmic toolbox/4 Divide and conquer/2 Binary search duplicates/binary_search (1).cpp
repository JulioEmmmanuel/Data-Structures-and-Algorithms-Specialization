#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long> &a, int x)
{
  int left = 0, right = (int)a.size() - 1;
  int possible = -1;
  //write your code here
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (a[mid] == x)
    {
      possible = mid;
      right = mid - 1;
    }
    else if (x > a[mid])
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return possible;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  std::cout << '\n';
}
