/*
题目描述:

现在现在有一台机器，这台机器可以接收两种形式任务：（1）任务列表，任务列表里面有N个任务，对于第i个任务，机器在Ti时间开始执行，并在1个单位时间内做完。
（2）临时任务，机器可以在任意时间接收一个临时任务，但任务列表里面的任务优先级要高于临时任务，也就是说当机器空闲的时候才会执行临时任务。
现在机器已经接收一个任务列表。接下来会有M个临时任务，我们想知道每个临时任务何时被执行。为了简化问题我们可以认为这M个临时任务是独立无关即任务是可以同时执行的，互不影响的。
输入
输入数据有多组，每组数据第一行包括两个整数N和M（1<=N, M<=10^5）。
接下来一行有N个不同数字T1,T2,T3.....TN（1<=T1
接下来又M行，每行一个数字Qi（1<=Qi<=10^9），表示第i个临时任务的的接收时间。
输出
对于每个临时任务，输出它被执行的时间。
样例输入
5 6
1 2 3 5 6
3
2
1
4
5
6
样例输出
4
4
4
4
7
7
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_INT ((unsigned)(-1)>>1)
#define num 10010
int a[num];
/*
int main(int argc, char const *argv[]) {
  int M, N;
  int T[num] = {0}, tp[num] = {0};
  int i = 0, temp;
  cin >> N >> M;
  while(i < N){//将任务列表中的数作为数组下标，并标记为1
    cin >> temp;
    T[temp] = 1;
    i ++;
  }
  i = 0;
  while(i < M){
    cin >> temp;
    int j;
    for(j = temp; j < num && T[j] > 0; j ++){
    //找到T[j] = 0即任务列表中空闲时间段的部分
    }
    tp[i] = j;
    i ++;
  }
  for(i = 0; i < M; i ++){
    cout << tp[i] << endl;
  }
  return 0;
}*/

int solve(int left, int right){
  int id_x, start = left;
  while(left <= right){
    int mid = (left + right) / 2;
    if(a[mid] - a[start] == mid - start){
      left = mid + 1;
      id_x = mid;
    }else{
      right = mid - 1;
    }
  }
  return a[id_x] + 1;
}

int main(){
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i ++){
    cin >> a[i];
  }
  while(M--){
    int q;
    cin >> q;
    int id_x = lower_bound(a, a+N, q) - a;//a中元素大于等于q的数组下标
    if(id_x == N || a[id_x] != q){//等于N 或者a[id_x]>q
      cout << q << endl;
    }else{
      cout << solve(id_x, N-1) << endl;
    }
  }
  return 0;
}
