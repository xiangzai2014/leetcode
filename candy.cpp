/*There are N children standing in a line. Each child is assigned a rating
value.
You are giving candies to these children subjected to the following
requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int len = ratings.size();
    if (len == 1)
      return 1;

    int sum = 0;
    vector<int> v(len, 1); //初始将每个孩子的糖果数都设为1

    //从左向右扫描，保证一个方向上rate大的糖果更多
    for (int i = 1; i < len; i++) {
      if (ratings[i] > ratings[i - 1]) {
        v[i] = v[i - 1] + 1;
      }
    }

    //从右向左扫描，保证另一个方向上的rate大的糖果更多
    for (int i = len - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1] && v[i] <= v[i + 1]) {
        v[i] = v[i + 1] + 1;
      }
    }

    for (int i = 0; i < len; i++) {
      sum += v[i];
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  int v1[10] = {1, 1, 3, 2, 1, 5, 4, 1, 2, 3};
  vector<int> v(&v1[0], &v1[10]);
  Solution s;
  cout << s.candy(v);
  return 0;
}
