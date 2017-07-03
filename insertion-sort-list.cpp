/*Sort a linked list using insertion sort.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == NULL)
      return head;
    ListNode *first;
    ListNode *t, *p, *q;
    first = head->next;
    head->next = NULL;
    while (first != NULL) {
      for (t = first, q = head; ((q != NULL) && (t->val > q->val));
           p = q, q = q->next) {
      }
      //待比较的数 > 原链表中的数 直到找到不满足条件的
      first = first->next;
      if (q == head) {
        head = t;
      } else {
        p->next = t;
      }
      t->next = q;
    }
    return head;
  }
};

int main() {
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(1);
  ListNode *l4 = new ListNode(5);
  ListNode *dummy = new ListNode(4);
  ListNode *head = dummy;
  head->next = l1;
  head = head->next;
  head->next = l2;
  head = head->next;
  head->next = l3;
  head = head->next;
  head->next = l4;
  Solution s;
  head = dummy;
  head = s.insertionSortList(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}

/*
// 1. 添加了个伪链表头，简化设计// 2. 利用递归
class Solution {
public:
       ListNode *insertionSortList(ListNode *head) {
            if (!head || !head->next) return head;
            ListNode dummyHead(0), *p;
            dummyHead.next = insertionSortList(head->next);
            p = &dummyHead;
            while (p && p->next && head->val > p->next->val) {
                  p = p->next;
            }
            head->next = p->next;
            p->next = head;
            return dummyHead.next;
        
  }
};
*/
