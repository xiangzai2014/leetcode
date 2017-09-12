#include <iostream>
#include <stack>
#include <queue>
#include "binaryTree.h"
using namespace std;

//建立二叉树
TreeNode* Tree::createTree(){
    TreeNode* cur = 0;
    int val;
    cin >> val;
    if(val == -1){
        return NULL;
    }
    else{
        cur = new TreeNode;
        cur->data = val;
        cur->lchild = createTree();
        cur->rchild = createTree();
        root = cur;
        return cur;
    }
}

//中序访问二叉树（递归）
void Tree::inOrder(TreeNode* r){
    if(r!=0){
        inOrder(r->lchild);
        cout << r->data << " ";
        inOrder(r->rchild);
    }
}

//利用重载的方法
void Tree::inOrder(){
    inOrder(root);
    cout << endl;
}

//中序遍历（非递归）
void Tree::notReinOrder(){
    stack<TreeNode*> s;
    TreeNode* r = getRoot();
    while(!s.empty() || r!=0){
        while(r!=0){
            s.push(r);
            r = r -> lchild;
        }
        if(!s.empty()){
            r = s.top();
            s.pop();
            cout << r->data << " ";
            r = r->rchild;
        }
    }
    cout << endl;
}

//前序遍历（递归
void Tree::preOrder(TreeNode* r){
    if(r!=0){
        cout << r->data << " ";
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}
//重载
void Tree::preOrder(){
    preOrder(root);
    cout << endl;
}

//前序遍历（非递归
void Tree::notRepreOrder(){
    stack<TreeNode*> s;
    TreeNode* r = getRoot();
    s.push(r);
    while(!s.empty()){
        r = s.top();
        s.pop();
        cout << r->data << " ";
        if(r->rchild != 0){
            s.push(r->rchild);
        }
        if(r->lchild != 0){
            s.push(r->lchild);
        }
    }
    cout << endl;
}

//后序遍历（递归
void Tree::postOrder(TreeNode* r){
    if(r!=0){
        postOrder(r->lchild);
        postOrder(r->rchild);
        cout << r->data << " ";
    }
}
//重载
void Tree::postOrder(){
    postOrder(root);
    cout << endl;
}

//后序非递归访问要定义新的结构体类型
struct Node{
    TreeNode* tp;
    bool flag;
};
//后续遍历（递归
void Tree::notRepostOrder(){
    Node node;
    stack<Node> s;
    TreeNode* r = getRoot();
    while(!s.empty() || r!=0){
        while(r!=0){
            node.tp = r;
            node.flag = 0;
            s.push(node);
            r = r->lchild;
        }

        if(!s.empty()){
            node = s.top();
            s.pop();
            r = node.tp;
            if(node.flag == 1){
                cout << r->data << " ";
                r = 0;//表示已经访问了该结点
            }else{
                node.flag = 1;
                s.push(node);
                r = r->rchild;
            }
        }
    }
    cout << endl;
}

//求二叉树结点个数
int Tree::treeSize(TreeNode *r){
  //二叉树结点的个数为左右子树高度和+1
  if(r == 0) return 0;
  else{
    return (1+treeSize(r->lchild)+treeSize(r->rchild));
  }
}
//重载
int Tree::treeSize(){
  return treeSize(root);
}

//求二叉树叶子结点个数
int Tree::treeLeaves(TreeNode *r){
  //当为空时，返回0；当找到叶子时返回1
  if (r==0) {
    return 0;
  }else if(r->lchild==0 && r->rchild==0){
    return 1;
  }else{
    return treeLeaves(r->lchild)+treeLeaves(r->rchild);
  }
}
//重载
int Tree::treeLeaves(){
  return treeLeaves(root);
}

//求二叉树的高度
int Tree::treeHeight(TreeNode *r){
  if(r==0) return 0;
  else{
    //二叉树的高度为左右子树的最大者+1
    int lheight = treeHeight(r->lchild);
    int rheight = treeHeight(r->rchild);
    return (lheight > rheight) ? lheight+1 : rheight+1;
  }
}

//层次遍历求树高 需利用新的结构
struct LayerTreeNode{
  TreeNode* ptr;
  int height;
};

int Tree::layerHeight(){
  queue<LayerTreeNode> que;
  LayerTreeNode temp, lTemp, rTemp;
  TreeNode *r = getRoot();
  int height1 = 1;
  temp.ptr = r;
  temp.height = 1;
  que.push(temp);//先将根对应的LayerBTreeNode对象进队
  while(!que.empty()){
    temp = que.front();
    que.pop();
    r = temp.ptr;

    //用当前的高度跟取出的队首进行比较
    if(height1 < temp.height){
      height1 = temp.height;
    }
    if(r->lchild != 0 || r->rchild != 0){
      ////如果它的左右子树不为空，则进队列
      if(r->lchild != 0){
        lTemp.ptr = r->lchild;
        lTemp.height = temp.height + 1;//在原来高度基础上加1,再入队列
        que.push(lTemp);
      }
      if(r->rchild != 0){
        rTemp.ptr = r->rchild;
        rTemp.height = temp.height + 1;
        que.push(rTemp);
      }
    }
  }
  return height1;
}
