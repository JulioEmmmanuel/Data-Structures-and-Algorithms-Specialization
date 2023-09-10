#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

struct Node
{
  long key;
  int left;
  int right;
  bool processed = false;
  long min = 0;
  long max = 0;

  Node() : key(0), left(-1), right(-1)
  {
  }
  Node(long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(vector<Node> &tree)
{

  if (tree.size() == 0)
  {
    return true;
  }

  Node *n = &tree[0];
  stack<Node *> nodes;
  nodes.push(n);
  while (!nodes.empty())
  {
    n = nodes.top();

    bool pushed = false;

    if (n->left != -1 && !tree[n->left].processed)
    {
      nodes.push(&tree[n->left]);
      pushed = true;
    }

    if (n->right != -1 && !tree[n->right].processed)
    {
      nodes.push(&tree[n->right]);
      pushed = true;
    }

    if (pushed)
    {
      continue;
    }

    n->min = n->key;
    n->max = n->key;

    if (n->right != -1)
    {
      n->min = std::min(tree[n->right].min, n->min);
      n->max = std::max(tree[n->right].max, n->max);

      if (tree[n->right].min < n->key)
      {
        return false;
      }
    }

    if (n->left != -1)
    {

      n->min = std::min(tree[n->left].min, n->min);
      n->max = std::max(tree[n->left].max, n->max);

      if (tree[n->left].max >= n->key)
      {
        return false;
      }
    }


    n->processed = true;
    nodes.pop();
  }

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
