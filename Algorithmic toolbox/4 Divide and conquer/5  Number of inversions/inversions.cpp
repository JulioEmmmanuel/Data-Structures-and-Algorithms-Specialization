#include <iostream>
#include <vector>

using std::vector;

int merge(vector<long> &a, int l, int m, int r){
  int n1 = (m - l) + 1;
  int n2 = (r - m);
  int L[n1];
  int R[n2];
  for (int i = 0; i < n1; i++){
    L[i] = a[l + i];
  }
  for (int j = 0; j < n2; j++){
    R[j] = a[m + j + 1];
  }
  int i = 0;
  int j = 0;
  int pos = l;

  int inversions = 0;

  while (i < n1 && j < n2)
  {
    if(L[i] <= R[j]){
      a[pos++] = L[i++];
    } else {
      a[pos++] = R[j++];
      inversions += (n1 - i);
    }
  }

  while(i < n1){
    a[pos++] = L[i++];
  }

  while(j < n2){
    a[pos++] = R[j++];
  }

  return inversions;
}

int sortAndCount(vector<long> &a, int l, int r){
  if(l >= r){
    return 0;
  }

  int m = (l + r) / 2;
  int n1 = sortAndCount(a, l, m);
  int n2 = sortAndCount(a, m + 1, r);
  return n1 + n2 + merge(a, l, m, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << sortAndCount(a, 0, a.size()-1) << '\n';
}
