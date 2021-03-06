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
#include <vector>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n+1, 0);
  int dead = 0; //表示已经死了的人数
  int num = 0; // 模拟没有被杀的人的喊得数
  for(int i = 1; i <= n; i ++){
    a[i] = i;
  }
  for(int i = 1; ; i ++){
    if(i > n){//如果大于总人数，我们就从头开始
      i = i % n;
    }
    if(a[i] > 0){//如果当前这个人没有死，就报数
      num ++;
    }
    if(k == num && dead != n-1){//如果当前这个人报的数等于k 并且没有已经死亡n-1个人
      num = 0;
      a[i] = 0;
      dead ++;
    }else if(k == num && dead == n-1){//如果这个人报数等于k，并且已经死了n-1个人，说明当前这个人就是最后的一个活着的了。。
      cout << "活着的为第" << a[i] << "个人" << endl;
      break;
    }
  }
  return 0;
}
