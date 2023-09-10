#include <iostream>
#include <vector>

using std::vector;

using std::vector;

int lc[105][105][105];

int lcs3(const vector<long> &a, const vector<long> &b, const vector<long> &c) {
  //write your code here
  for(int k = 0; k<=c.size(); k++){
    for(int i = 0; i <= a.size(); i++){
      lc[i][0][k] = 0;
    }
    for(int j = 0; j <= b.size(); j++){
      lc[0][j][k] = 0;
    }
  }

  for(int i = 0; i<=a.size(); i++){
    for(int j = 0; j<=b.size(); j++){
      lc[i][j][0] = 0;
    }
  }

  for(int i = 1; i <= a.size(); i++){
    for(int j = 1; j <= b.size(); j++){
      for(int k = 1; k<= c.size(); k++){
        if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
          lc[i][j][k] = lc[i-1][j-1][k-1] + 1;
        } else {
          lc[i][j][k] = std::max(lc[i-1][j][k], std::max(lc[i][j-1][k], lc[i][j][k-1]));
        }
      }
    }
  }

  return lc[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<long> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<long> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<long> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
