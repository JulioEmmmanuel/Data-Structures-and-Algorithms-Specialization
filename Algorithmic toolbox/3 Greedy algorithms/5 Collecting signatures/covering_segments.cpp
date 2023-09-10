#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h>

using std::greater;
using std::vector;

class Segment {
  public:

    int start;
    int end;

    Segment(){

    }

    Segment(int s, int e){
      start = s;
      end = e;
    }

    bool operator<(Segment const & other){
      return end < other.end;
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int last = -1;
  sort(segments.begin(), segments.end());
  //write your code here
  for (int i = 0; i < segments.size(); i++) {
    if(last < segments[i].start){
        points.push_back(segments[i].end);
        last = segments[i].end;
    }
  }
  return points;
}

int main() {
  int n, start, end;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> start >> end;
    Segment seg(start, end);
    segments[i] = seg;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << "\n";
}
