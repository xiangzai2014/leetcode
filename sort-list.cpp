/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
/*
 考点：  1. 快慢指针；2. 归并排序。  
此题经典，需要消化吸收。  
复杂度分析:             
       T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n            
      /    \           以下依此类推：          
   T(n/2) T(n/2)      一共是 n/2*2 = n         
   /    \  /     \        
T(n/4) ...........   一共是 n/4*4 = n       
一共有logn层，故复杂度是 O(nlogn) 

*/
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
  //寻找链表中间点
  ListNode *findMiddle(ListNode *head) {
    ListNode *chaser = head;
    ListNode *runner = head->next;
    while (runner != NULL && runner->next != NULL) {
      chaser = chaser->next;
      runner = runner->next->next;
    }
    return chaser;
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val > l2->val) {
        head->next = l2;
        l2 = l2->next;
      } else {
        head->next = l1;
        l1 = l1->next;
      }
      head = head->next;
    }
    if (l1 == NULL) {
      head->next = l2;
    }
    if (l2 == NULL) {
      head->next = l1;
    }
    return dummy->next;
  }
  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *middle = findMiddle(head);
    ListNode *right = sortList(middle->next);
    middle->next = NULL;
    ListNode *left = sortList(head);
    return mergeTwoLists(left, right);
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
  head = s.sortList(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}
