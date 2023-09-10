#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

#define MAX 30

using std::vector;
using std::string;
using std::max;
using std::min;

long long mins[MAX][MAX];
long long maxs[MAX][MAX];

vector<int> nums;
vector<char> ops;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void min_and_max(int i, int j){
  long long m = std::numeric_limits<long long>::max();
  long long M = std::numeric_limits<long long>::min();
  for (int k = i; k < j; k++){
    long long a = eval(maxs[i][k], maxs[k + 1][j], ops[k]);
    long long b = eval(maxs[i][k], mins[k + 1][j], ops[k]);
    long long c = eval(mins[i][k], maxs[k + 1][j], ops[k]);
    long long d = eval(mins[i][k], mins[k + 1][j], ops[k]);
    m = min(m, min(a, min(b, min(c, d))));
    M = max(M, max(a, max(b, max(c, d))));
  }
  mins[i][j] = m;
  maxs[i][j] = M;
}

long long get_maximum_value(const string &exp) {

  for (int i = 0; i < exp.size(); i++){
    if(isdigit(exp[i])){
      nums.push_back(exp[i]-48);
    } else {
      ops.push_back(exp[i]);
    }
  }

  int n = nums.size();

  for (int i = 0; i < n; i++){
    mins[i][i] = nums[i];
    maxs[i][i] = nums[i];
  }

  for (int s = 1; s <= n - 1; s++)
  {
    for (int i = 0; i < n - s; i++)
    {
      int j = i + s;
      min_and_max(i, j);
    }
  }

    return maxs[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
