/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
      vector<vector<int> > res(numRows);
      for(int i = 0; i < numRows; i ++){
        res[i].push_back(1);//第一个位置为1
        for(int j = 1; j < i; j ++){
          res[i].push_back(res[i-1][j] + res[i-1][j-1]);//i>=2的时候执行这一部分
        }
        if(i>0) res[i].push_back(1);//最后一个也是1，注意不能在第一行中添加
      }
      return res;
    }
};//运行时间：3ms  占用内存：624k

int main(){
  Solution s;
  vector<vector<int> > result;
  result = s.generate(6);
  vector<int> temp_result;
  for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it++){
      temp_result = *it;
      for(vector<int>::iterator ite = temp_result.begin(); ite != temp_result.end(); ite ++){
          cout << *ite << " ";
      }
      cout << '\n';
  }
  return 0;
}
