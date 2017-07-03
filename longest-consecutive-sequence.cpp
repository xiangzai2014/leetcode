/*
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.
For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.
Your algorithm should run in O(n) complexity.
*/
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
//用hash表来解决这个问题，先初始化一个hash表， 存储所有数组元素，
//然后遍历这个数组， 对找到的数组元素，
//去搜索其相连的上下两个元素是否在hash表中， 如果在，
//删除相应元素并增加此次查找的数据长度， 如果不在，
//从下一个元素出发查找。已经访问过的元素记录下来或者删除，因为访问过的长度已经知道了额
//每次循环o(1),整体o(n)
class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> myset(num.begin(), num.end());
    int result = 1;
    for (int current : num) {
      /* code */
      if (myset.find(current) == myset.end())
        continue;
      myset.erase(current);
      int prev = current - 1;
      int post = current + 1;
      while (myset.find(prev) != myset.end()) {
        myset.erase(prev--);
      }
      while (myset.find(post) != myset.end()) {
        myset.erase(post++);
      }
      result = max(result, post - prev - 1);
    }

    return result;
  }
};
