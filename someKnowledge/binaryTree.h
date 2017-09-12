#ifndef BINARY_TREE_H
#define BINARY_TREE_H
struct TreeNode{
  int data;
  TreeNode *lchild, *rchild;
};
class Tree{
private:
  TreeNode* root;
public:
  void setRoot(TreeNode *r){root = r;}
  TreeNode* getRoot(){return root;}
  TreeNode* createTree();
  //中序遍历(递归)
  void inOrder();
  //中序遍历(非递归)
  void notReinOrder();

  //前序遍历（递归）
  void preOrder();
  //前序遍历（非递归）
  void notRepreOrder();

  //后序遍历(递归)
  void postOrder();
  //后序遍历(非递归)
  void notRepostOrder();

  //求结点个数
  int treeSize();
  //求叶子结点个数
  int treeLeaves();

  //求树高(递归)
  int treeHeight();
  //层次法求树高
  int layerHeight();
protected:
  //中序遍历 前序遍历 后序遍历
  void inOrder(TreeNode*);
  void preOrder(TreeNode*);
  void postOrder(TreeNode*);

  //结点个数
  int treeSize(TreeNode*);
  int treeLeaves(TreeNode*);
  int treeHeight(TreeNode*);
};


#endif
