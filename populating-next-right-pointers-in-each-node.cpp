/*
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set toNULL.
Initially, all next pointers are set toNULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 */
#include <iostream>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
//递归版本
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if(root == NULL){
        return;
      }
      if(root->left != NULL && root->right != NULL){
        root->left->next = root->right;
      }
      if(root->right != NULL && root->next != NULL){
        root->right->next = root->next->right;
      }
      connect(root->left);
      connect(root->right);
    }

};//运行时间：7ms 、占用内存：876k
*/

//层次遍历
class Solution{
public:
  void connect(TreeLinkNode *root) {
    if(root==NULL){
      return;
    }
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left){
      cur = pre;
      while(cur){
        cur->left->next = cur->right;
        if(cur->next) cur->right->next = cur->next->left;
        cur = cur->next;
      }
      pre = pre->left;
    }
  }
};//运行时间：6ms   占用内存：888k
