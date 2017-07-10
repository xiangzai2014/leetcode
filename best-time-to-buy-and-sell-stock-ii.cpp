/*Say you have an array for which the i th element is
the price of a given stock on day i.
Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie,
buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>
using namespace std;
//贪心法，又称贪心算法，是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，
//从而希望导致结果是最好或最优的算法。他所做出的仅是在某种意义上的局部最优解。
//贪心算法不是对所有问题都能得到整体最优解，但对范围相当广泛的许多问题他能产生整体最优解或者是整体最优解的近似解。

//时间O(n)，空间O(1)。
//当股票高于前一天时，可获利润，累加所有的利润即可获得最大值
class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int len = prices.size();
      if(len < 2) return 0;
      int maxProfit = 0;
      for(int i = 1; i < len; i ++){
        int diff = prices[i] - prices[i-1];
        if(diff > 0){
          maxProfit += diff;
        }
      }
      return maxProfit;
    }
};//运行时间：4ms  占用内存：496k

int main(int argc, char const *argv[]) {
  vector<int> prices;
  prices.push_back(3);
  prices.push_back(2);
  prices.push_back(4);
  prices.push_back(1);
  prices.push_back(5);
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}
