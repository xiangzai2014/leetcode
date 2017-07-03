/*Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,
       1
      / \
     2   3

Return6.
*/

/**
 * Definition for binary tree
 **/
#include <cmath>
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxSum(TreeNode *root, int &mRes) {
    if (root == NULL) {
      return 0;
    }
    int l = maxSum(root->left, mRes);
    int r = maxSum(root->right, mRes);
    int mVal = ::max(l, r) + root->val;
    int curPath = l + r + root->val;
    mRes = ::max(mRes, ::max(curPath, mVal));
    if (mVal < 0)
      mVal = 0;
    if (curPath < 0)
      curPath = 0;
    return mVal;
  }
  int maxPathSum(TreeNode *root) {
    if (root == NULL)
      return 0;
    int mRes = root->val;
    maxSum(root, mRes);
    return mRes;
  }
};

int main() {
  TreeNode *p1 = new TreeNode(1);
  TreeNode *p2 = new TreeNode(2);
  TreeNode *p3 = new TreeNode(3);
  p1->left = p2;
  p1->right = p3;

  Solution solution;
  int result = solution.maxPathSum(p1);
  std::cout << result << '\n';
  return 0;
}
