#include <iostream>
#include <vector>

using std::vector;

long lc[105][105];

long lcs2(const vector<long> &a, const vector<long> &b) {
  //write your code here
  for(int i = 0; i <= a.size(); i++){
    lc[i][0] = 0;
  }
  for(int j = 0; j <= b.size(); j++){
    lc[0][j] = 0;
  }

  for(int i = 1; i <= a.size(); i++){
    for(int j = 1; j <= b.size(); j++){
      if(a[i-1] == b[j-1]){
        lc[i][j] = lc[i-1][j-1] + 1;
      } else {
        lc[i][j] = std::max(lc[i-1][j], lc[i][j-1]);
      }
    }
  }

  return lc[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
