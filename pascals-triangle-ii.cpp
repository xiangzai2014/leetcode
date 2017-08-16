/*
Given an index k, return the k th row of the Pascal's triangle.
For example, given k = 3,
Return[1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
//杨辉三角形。
//杨辉三角形第n层（顶层称第0层，第1行，第n层即第n+1行，此处n为包含0在内的自然数）正好对应于二项式(a+b)^n展开的系数。
//例如第二层1 2 1是幂指数为2的二项式展开形式的系数。

//本题中的k指的是层数n
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> result(rowIndex+1, 1);
      for(int i = 0; i <= rowIndex; i ++){
        for(int j = i-1; j>=1; j --){
          result[j] = result[j-1] + result[j];
        }
      }
      return result;
    }
};//运行时间：3ms   占用内存：492k

int main(){
  Solution s;
  vector<int> result;
  result = s.getRow(999);
  for(vector<int>::iterator it = result.begin(); it != result.end(); it ++){
    cout << *it << " ";
  }
  cout << '\n';
  return 0;
}
