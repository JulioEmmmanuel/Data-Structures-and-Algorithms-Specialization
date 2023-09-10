#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

struct worker {
  int idx;
  long long finish_time = 0;
};

class Compare
{
public:
  bool operator()(worker w1, worker w2){
    if (w1.finish_time > w2.finish_time){
      return true;
    } else if(w1.finish_time < w2.finish_time){
      return false;
    } else {
      return w1.idx > w2.idx;
    }
  }
};

class JobQueue
{
private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    int time;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
    assigned_workers_.resize(m);
    start_times_.resize(m);
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    priority_queue<worker, std::vector<worker>, Compare> pq;

    for (int i = 0; i < num_workers_; i++){
      worker w;
      w.idx = i;
      pq.push(w);
    }

    for (int i = 0; i < jobs_.size(); i++)
    {
      int duration = jobs_[i];
      worker w = pq.top();
      assigned_workers_[i] = w.idx;
      start_times_[i] = w.finish_time;
      w.finish_time += duration;
      pq.pop();
      pq.push(w);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
