/*Given an array of integers, every element appears three times except for one.
Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?
*/
#include <iostream>
using namespace std;
class Solution {
public:
  int singleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      //纪录i位置上1的个数
      int count = 0;
      for (int j = 0; j < n; j++) {
        if ((A[j] >> i & 1) == 1) {
          count++;
        }
      }
      //把3n+1的那些位的1移回原位并累加起来
      result += ((count % 3) << i);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  int A[13] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 5};
  Solution solution;
  int res = solution.singleNumber(A, 13);
  cout << res << endl;
  return 0;
}
