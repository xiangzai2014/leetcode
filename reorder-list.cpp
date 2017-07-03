/*Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…
You must do this in-place without altering the nodes' values.
For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
*/
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*方法一：使用栈存储逆序，将逆序插入到原序列中，结束标志是当前节点和插入节点相同(奇偶都相同)*/
/*class Solution {
public:
  void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return;
    }
    stack<ListNode *> st; //用来存储倒序元素
    ListNode *cur = head;
    while (cur != NULL) {
      st.push(cur);
      cur = cur->next;
    }
    cur = head;
    ListNode *post = NULL; //用于存储倒序栈中的第一个元素
    while (cur != post) {
      post = st.top();
      st.pop();
      post->next = cur->next;
      cur->next = post;
      cur = post->next;
    }
    cur->next = NULL; //将最后的中间节点的设置为NULL
  }
};
*/
/*方法二：快慢指针法
*/
class Solution {
public:
  void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
      return;
    }
    //快慢指针找中点
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }

    //对slow后面的部分逆序
    fast = slow->next;
    slow->next = NULL;
    while (fast != NULL) {
      ListNode *temp = fast->next;
      fast->next = slow->next;
      slow->next = fast;
      fast = temp;
    }

    //合并slow前面和后面的部分
    ListNode *p = head;
    ListNode *q = slow->next;
    while (p != NULL && q != NULL) {
      slow->next = q->next;
      q->next = p->next;
      p->next = q;
      p = q->next;
      q = slow->next;
    }
  }
};

int main(int argc, char const *argv[]) {
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  ListNode *head = l1;
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;
  Solution s;
  s.reorderList(l1);
  head = l1;
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;
  return 0;
}
