/*Say you have an array for which the i th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock), design an algorithm to find
the maximum profit.*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int len = prices.size();
      if(len < 2) return 0;
      int minPrice = prices[0];
      int maxProfit = 0;
      for(int i = 1; i < len; i ++){
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
      }
      return maxProfit;
    }
};//运行时间：1ms  占用内存：384k

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
