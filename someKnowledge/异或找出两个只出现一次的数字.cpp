/***
题目：

已知数组中数字两两相同，有两个不同，找出这两个不相同的数字

解答过程：

如果数组中只有一个数字的话，那么我们就可以直接异或就OK了，但是现在有两个的话就会有点麻烦了，所以就有一个非常精彩的思想。
首先我们将所有的数字进行异或，结果肯定不会为 0 所以我们将其进行位运算的话一定会有第 index 位是 1, 所以我们将其分为两组，
一组是第 index 位是 1 的数，另一组是第 index 位是 0的数，而这两组数中，那两个不同的数字一定是分开的，所以我们将这两组数字分别进行异或就找出来了。
***/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n;
  vector<int> a;
  int tmp;
  while(cin >> n){//n必须为偶数
    int sum = 0;
    for(int i= 0; i < n; i ++){
      cin >> tmp;
      a.push_back(tmp);
      sum = sum ^ tmp;
    }
    if(n & 1) return 0;//n为奇数
    int index = 0;//index判断是 从右边判断第index位为 1
    while(1){
      if(sum & 1){
        break;
      }
      index ++;
      sum >>= 1;
    }
    int num1 = 0, num2 = 0;
    for(int i = 0; i < n; i ++){
      if((a[i] >> index) & 1){//第 index 位是 1 的
        num1 ^= a[i];
      }else{//第 index 位是 0 的
        num2 ^= a[i];
      }
    }
    cout << num1 << " " << num2 << endl;
  }

  return 0;
}
