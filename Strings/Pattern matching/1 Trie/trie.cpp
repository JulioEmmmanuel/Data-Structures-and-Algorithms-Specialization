#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  t.push_back(map<char, int>());

  for(int i = 0; i < patterns.size(); i++){

    string pat = patterns[i];
    int curr = 0;
    for(int j = 0; j < pat.size(); j++){
      char c = pat[j];
      if(t[curr].find(c) != t[curr].end()){
        curr = t[curr][c];
      } else {
        t[curr][c] = t.size();
        t.push_back(map<char, int>());
        curr = t[curr][c];
      }

    }
  }

  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}