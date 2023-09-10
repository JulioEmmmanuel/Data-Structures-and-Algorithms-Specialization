#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::sort;
using std::stable_sort;
using std::vector;

class Point {
  public:
    long value;
    char type;
    int index;

    Point(){

    }

    Point(long value, char type, int i)
    {
      this->value = value;
      this->type = type;
      this->index = i;
    }
};

bool sort_points(const Point &a, const Point &b){
  if(a.value == b.value){
    return a.type < b.type;
  }
  return a.value < b.value;
}

vector<int> count_segments(vector<Point> points, int m) {
  vector<int> cnt(m);
  //write your code here
  sort(points.begin(), points.end(), sort_points);

  int current = 0;

  for (int i = 0; i < points.size(); i++)
  {

    if(points[i].type == 'b'){
      current++;
    } else if(points[i].type == 'e'){
      current--;
    } else {
      cnt[points[i].index] = current;
    }
  }

  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<Point> points(2*n + m);
  long start, end;
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> start >> end;
    Point p(start, 'b', -1);
    Point e(end, 'e', -1);
    points[i] = p;
    points[n + i] = e;
  }
  for (size_t i = 0; i < m; i++) {
    std::cin >> start;
    Point p(start, 'c', i);
    points[2*n + i] = p;
  }
  //use fast_count_segments
  vector<int> cnt = count_segments(points, m);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  std::cout << '\n';
}
