/*Given an array of integers, every element appears twice except for one. Find
that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?
*/
#include <iostream>
using namespace std;

//用异或。二进制异或，两位相同为0，不同得1。即两个数相同，异或得0.
// 0和任何数异或得到该数本身。
//将数组中所有数进行异或，其中出现两次的数抵消为0，剩下的就是出现一次的那个数。
class Solution {
public:
  int singleNumber(int A[], int n) {
    if (n == 1)
      return A[0];
    int temp = A[0];
    for (int i = 1; i < n; i++) {
      temp ^= A[i];
    }
    return temp;
  }
};
