/*
Say you have an array for which the i th element is the price of a given stock(股票)
on day i.
Design an algorithm to find the maximum profit. You may complete at most two
transactions.
Note:
You may not engage in multiple transactions(事务) at the same time (ie, you must sell
the stock before you buy again).
*/

#include <iostream>
#include <vector>
using namespace std;

//动态规划的思想进行改进，保持中间计算的结果，减少重复计算 时间复杂度为O(n)
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int len = prices.size();
    if(len == 0) return 0;
    int ansResult = 0;
    //正向遍历，opt[i]表示prices[0..i]内做一次最大交易的最大收益
    vector<int> opt(len, 0);
    int minPrice = prices[0];
    int curAns = 0;
    for(int i = 1; i < len; i ++){
      if(prices[i] < minPrice)
        minPrice = prices[i];
      else if(prices[i] - minPrice > curAns){
        curAns = prices[i] - minPrice;
      }
      opt[i] = curAns;
    }
    //逆向遍历，optReverse[i]表示prices[i..n-1]内做一次交易的最大收益
    vector<int> optReverse(len, 0);
    curAns = 0;
    int maxPrice = prices[len-1];
    for(int i = len - 2; i >= 0; i --){
      if(prices[i] > maxPrice)
        maxPrice = prices[i];
      else if(maxPrice - prices[i] > curAns){
        curAns = maxPrice - prices[i];
      }
      optReverse[i] = curAns;
    }
    for(int i = 0; i < len; i ++){
      int temp = opt[i] + optReverse[i];
      if(ansResult < temp){
        ansResult = temp;
      }
    }
    return ansResult;
  }
};//运行时间：2ms 占用内存：492k

int main(int argc, char const *argv[]) {
  vector<int> prices;
  for (int i = 0; i < 2; i++)
  {
    prices.push_back(i);
  }
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}
