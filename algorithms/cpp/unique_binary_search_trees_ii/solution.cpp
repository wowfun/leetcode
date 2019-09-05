#include<iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<TreeNode *> generateTreesUsingRecursion(const int start, const int end) {
    if (start > end) return {NULL};
    vector<TreeNode *> trees;
    for (int i = start; i <= end; i++) {
      for (TreeNode *leftRoot : generateTreesUsingRecursion(start, i - 1)) { // left child, low..i - 1
        for (TreeNode *rightRoot : generateTreesUsingRecursion(i + 1, end)) { // right child i+1..high
          TreeNode *root = new TreeNode(i);
          root->left = leftRoot;
          root->right = rightRoot;
          trees.push_back(root);
        }
      }
    }
    return trees;
  }

  vector<TreeNode *> generateTrees(int n) {
    if(!n) return {};
    return generateTreesUsingRecursion(1, n);
  }
};
