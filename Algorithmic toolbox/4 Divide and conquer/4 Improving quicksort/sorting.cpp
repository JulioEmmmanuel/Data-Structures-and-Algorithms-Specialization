#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


void partition3(vector<long> &a, int l, int r, int &i, int &j)
{
  i = l+1, j = r;
  int p = l, q = r+1;
  int x = a[l];

  while(true){
    while(a[i] < x && i < r){
      i++;
    }
    while(a[j] > x && j > l){
      j--;
    }
    if(i >= j)
      break;

    swap(a[i], a[j]);
    if(a[i] == x){
      p++;
      swap(a[p], a[i]);
    }
    if(a[j] == x){
      q--;
      swap(a[q], a[j]);
    }
    i++;
    j--;
  }

  swap(a[l], a[j]);
  i = j + 1;
  j = j - 1;

  for (int k = l + 1; k <= p; k++){
    swap(a[k], a[j]);
    j--;
  }
  for (int k = r; k >= q; k--){
    swap(a[k], a[i]);
    i++;
  }
}

void randomized_quick_sort(vector<long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int i = l;
  int j = r;

  partition3(a, l, r, i, j);

  randomized_quick_sort(a, l, j);
  randomized_quick_sort(a, i, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}
