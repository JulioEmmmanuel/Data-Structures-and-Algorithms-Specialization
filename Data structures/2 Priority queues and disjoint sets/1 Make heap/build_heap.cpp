#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<long long> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // TODO: replace by a more efficient implementation
    for (int i = data_.size() / 2; i >= 0; i--){
      int fchild = 2 * i + 1;
      int schild = 2 * i + 2;
      int idx = i;
      int j = i;
      while (fchild < data_.size())
      {
        idx = j;
        if (data_[fchild] < data_[idx])
        {
          idx = fchild;
        }
        if (schild < data_.size() && data_[schild] < data_[idx])
        {
          idx = schild;
        }

        if(idx != j){
          swap(data_[j], data_[idx]);
          swaps_.push_back(make_pair(j, idx));
          fchild = 2 * idx + 1;
          schild = 2 * idx + 2;
          j = idx;
        } else {
          break;
        }
      }
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
