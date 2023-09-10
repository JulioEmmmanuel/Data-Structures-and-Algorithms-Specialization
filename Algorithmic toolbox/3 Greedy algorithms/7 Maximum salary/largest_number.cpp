#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isBetter(string n1, string n2){
  string s1 = n1 + n2;
  string s2 = n2 + n1;
  return s1 > s2;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  while(!a.size() == 0){
    string max = a[0];
    int maxIdx = 0;
    for (int i = 0; i < a.size(); i++)
    {
      if(isBetter(a[i], max)){
        maxIdx = i;
        max = a[i];
      }
    }
    ret << max;
    a.erase(a.begin() + maxIdx);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << '\n';
}
