/***
思路：任何一个数字，跟自己异或都为0
如果一个数组中，只有一个数字出现一次，而其他数字都是成对出现的话，那么从头到尾将所有数字依次异或的话，最后得到的结果就是这个只出现一次的数字
***/
#include <iostream>
using namespace std;

int main(){
  int A[] = { 5, 5, 3, 3, 4, 8, 8 };
  int res = 0;
  for (int i = 0; i < 7; i++)
  {
    res ^= A[i];
  }
  cout << res << endl;
  return 0;
}
//应用：
//数组中有连个只出现一次的数字，其余都出现两次
