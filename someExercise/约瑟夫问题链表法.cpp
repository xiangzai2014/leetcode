/***********
题目：
n个人围成一个圈，每个人分别标注为1、2、...、n，要求从1号从1开始报数，报到k的人出圈，接着下一个人又从1开始报数，如此循环，直到只剩最后一个人时，该人即为胜利者。
例如当n=10,k=4时，依次出列的人分别为4、8、2、7、3、10，9、1、6、5，则5号位置的人为胜利者。给定n个人，请你编程计算出最后胜利者标号数。（要求用单循环链表完成。）
第一行为人数n;
第二行为报数k
10
4
********************/

#include <iostream>

using namespace std;

struct List{
  int data;
  struct List* next;
}LinkedList;

int main(){
  List *l, *r, *s;
  l = new List;
  r = l;
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i ++){///尾插法建立循环链表
    s = new List;
    s->data = i;
    r->next = s;
    r = s;
  }
  r->next = l->next;//让最后一个链表的下一个节点指向开头
  List *p = l->next;
  while(p->next != p){//开始模拟（判断条件要注意：因为最后肯定剩下一个人， 所以最后一个数据的next还是他本身)
    for(int i = 1; i < k-1; i ++){
      p = p->next;////每k个数死一个人
    }
    p->next = p->next->next;
    p = p->next;
  }

  cout << "活着的为第" << p->data << "个人" << endl;
  return 0;
}
