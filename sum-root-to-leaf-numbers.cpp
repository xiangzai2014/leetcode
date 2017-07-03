/*Given a binary tree containing digits from0-9only, each root-to-leaf path
could represent a number.
An example is the root-to-leaf path1->2->3which represents the number123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.
Return the sum = 12 + 13 =25.
*/
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//先序遍历，每次遍历将上一次sum×10+当前节点值，然后再将左右子树之和返回。
class Solution {
public:
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }

  int dfs(TreeNode *root, int sum) {
    if (!root)
      return 0;
    sum = sum * 10 + root->val;
    if (!root->left && !root->right)
      return sum;
    return dfs(root->left, sum) + dfs(root->right, sum);
  }
};
