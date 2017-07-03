/*A linked list is given such that each node contains an additional random
pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/
#include <iostream>
using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL)
      return NULL;
    RandomListNode *p = head;
    //拷贝新节点,插入到原节点的后边
    while (p != NULL) {
      RandomListNode *temp = p->next;
      RandomListNode *newNode = new RandomListNode(p->label);
      p->next = newNode;
      newNode->next = temp;
      p = temp;
    }
    // 拷贝随机指针
    p = head;
    while (p != NULL) {
      if (p->random != NULL) {
        p->next->random = p->random->next;
      }
      p = p->next->next;
    }
    //将新节点从原链表中分离出，注意要保证原链表正常
    p = head;
    RandomListNode *result = head->next;
    while (p->next != NULL) {
      RandomListNode *temp = p->next;
      p->next = p->next->next;
      p = temp;
    }
    return result;
  }
};

int main() {
  RandomListNode *p1 = new RandomListNode(1);
  RandomListNode *p2 = new RandomListNode(2);
  RandomListNode *p3 = new RandomListNode(3);
  RandomListNode *p4 = new RandomListNode(4);
  p1->next = p2;
  p1->random = p3;
  p2->next = p3;
  p2->random = p1;
  p3->next = p4;
  p3->random = p2;
  Solution solution;
  RandomListNode *result = solution.copyRandomList(p1);
  for (RandomListNode *i = result; i != NULL; i = i->next) {
    cout << i->label << " ";
  }
  return 0;
}
