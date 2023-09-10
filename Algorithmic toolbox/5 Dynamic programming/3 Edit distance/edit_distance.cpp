#include <iostream>
#include <string>

using std::string;

int distances[105][105];

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  for(int i = 0; i <= str1.size(); i++){
    distances[i][0] = i;
  }
  for(int j = 0; j <= str2.size(); j++){
    distances[0][j] = j;
  }

  for(int i = 1; i <= str1.size(); i++){
    for(int j = 1; j <= str2.size(); j++){
      int minD = std::min(distances[i-1][j], distances[i][j-1]);
      if(distances[i-1][j-1] <= minD){
        minD = distances[i-1][j-1];
        if(str1[i-1] == str2[j-1]){
          distances[i][j] = minD;
          continue;
        }
      }
      distances[i][j] = minD + 1;
    }
  }

  return distances[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
