/*
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.

For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/

 #include <iostream>
 using namespace std;

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
      TreeLinkNode *cur, *tail, *head;
      cur = root;
      head = tail = NULL;
      while(cur){
        if(cur->left){
          if(tail){
            tail = tail->next = cur->left;
          }
          else{
            head = tail = cur->left;
          }
        }
        if(cur->right){
          if(tail){
            tail = tail->next = cur->right;
          }
          else{
            head = tail = cur->right;
          }
        }
        if(!(cur=cur->next)){//若为NULL
          cur = head;
          head = tail = NULL;
        }
      }
    }
};//运行时间：14ms 占用内存：1140k
