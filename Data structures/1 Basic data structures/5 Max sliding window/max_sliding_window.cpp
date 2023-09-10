#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::max;
using std::vector;

struct num {
    int value;
    int idx;
};

deque<num> numdeq;

void addToDeque(int v, int i)
{
    while (!numdeq.empty() && numdeq.back().value <= v)
    {
        numdeq.pop_back();
    }

    num n;
    n.value = v;
    n.idx = i;

    numdeq.push_back(n);
}

void max_sliding_window(vector<int> const & A, int w) {

    for (int i = 0; i<w; i++){
        addToDeque(A[i], i);
    }

    std::cout << numdeq.front().value << std::endl;

    int low = 1;

    for (int i = w; i < A.size(); i++){
        if(numdeq.front().idx < low){
            numdeq.pop_front();
        }
        addToDeque(A[i], i);
        std::cout << numdeq.front().value << std::endl;
        low++;
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
