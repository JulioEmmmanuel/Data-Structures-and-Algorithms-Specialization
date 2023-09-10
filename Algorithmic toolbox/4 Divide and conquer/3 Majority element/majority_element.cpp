#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;



int get_majority_element(vector<long> &a, int left, int right) {

  if (left == right){
    return a[left];
  }

  //write your code here
  int mid = (left + right) / 2;
  long m1 = get_majority_element(a, left, mid);
  long m2 = get_majority_element(a, mid+1, right);

  if(m1 == -1 && m2 == -1){
    return -1;
  }

  int c1 = 0, c2 = 0;

  for (int i = left; i <= right; i++)
  {
    if (a[i] == m1)
    {
      c1++;
    } else if(a[i] == m2){
      c2++;
    }
  }


  if(c1 > (right-left + 1)/2){
    return m1;
  } else if(c2 > (right-left+1)/2){
    return m2;
  } else {
    return -1;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
