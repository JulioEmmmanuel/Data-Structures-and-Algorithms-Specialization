#include <iostream>
#include <vector>
#define MAX 1000

using std::vector;

bool dp[MAX][MAX];

bool partition3(vector<int> &A, int sum)
{

  dp[0][0] = true;

  for (int i = 0; i < A.size(); i++)
  {
    for (int j = sum; j >= 0; j--)
    {
      for (int k = sum; k >= 0; k--)
      {
        if (dp[j][k])
        {
          dp[j + A[i]][k] = true;
          dp[j][k + A[i]] = true;
        }
      }
    }
  }

    return dp[sum / 3][sum / 3];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
    sum += A[i];
  }

  if(n < 3 || sum % 3 != 0){
    std::cout << 0 << std::endl;
    return 0;
  }
  std::cout << partition3(A, sum) << '\n';
}
