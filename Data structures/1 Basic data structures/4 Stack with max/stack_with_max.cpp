#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::cout;
using std::max_element;
using std::string;
using std::vector;
using std::stack;

class StackWithMax {
    vector<int> s;
    stack<int> maxStack;

public:

    void Push(int value) {
        if(maxStack.empty() || value >= maxStack.top()){
            maxStack.push(value);
        }
        s.push_back(value);
    }

    void Pop() {
        assert(s.size());
        if(s[s.size()-1] == maxStack.top()){
            maxStack.pop();
        }
        s.pop_back();
    }

    int Max() const {
        assert(s.size());
        return maxStack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}