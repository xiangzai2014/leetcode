/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note: You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。最多交易k次，手上最多只能持有一支股票，求最大收益。
*/


/*
分析：特殊动态规划法。传统的动态规划我们会这样想，到第i天时进行j次交易的最大收益，要么等于到第i-1天时进行j次交易的最大收益（
第i天价格低于第i-1天的价格），要么等于到第i-1天时进行j-1次交易，然后第i天进行一次交易（第i天价格高于第i-1天价格时）。
于是得到动规方程如下（其中diff = prices[i] – prices[i – 1]）：

profit[i][j] = max(profit[i – 1][j], profit[i – 1][j – 1] + diff)
看起来很有道理，但其实不对，为什么不对呢？因为diff是第i天和第i-1天的差额收益，如果第i-1天当天本身也有交易呢（
也就是说第i-1天刚卖出了股票，然后又买入等到第i天再卖出），那么这两次交易就可以合为一次交易，这样profit[i – 1][j – 1] + diff
实际上只进行了j-1次交易，而不是最多可以的j次，这样得到的最大收益就小了。

那么怎样计算第i天进行交易的情况的最大收益，才会避免少计算一次交易呢？我们用一个局部最优解和全局最有解表示到第i天进行j次的收益，
这就是该动态规划的特殊之处。

我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义
global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为（其中diff = prices[i] – prices[i – 1]）：
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])，
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值，
而全局最优比较局部最优和前一天的全局最优。

local[i][j]和global[i][j]的区别是：local[i][j]意味着在第i天一定有交易（卖出）发生，当第i天的价格高于第i-1天（即diff > 0）时，
那么可以把这次交易（第i-1天买入第i天卖出）跟第i-1天的交易（卖出）合并为一次交易，即local[i][j]=local[i-1][j]+diff；
当第i天的价格不高于第i-1天（即diff<=0）时，那么local[i][j]=global[i-1][j-1]+diff，
而由于diff<=0，所以可写成local[i][j]=global[i-1][j-1]。global[i][j]就是我们所求的前i天最多进行k次交易的最大收益，
可分为两种情况：
如果第i天没有交易（卖出），那么global[i][j]=global[i-1][j]；
如果第i天有交易（卖出），那么global[i][j]=local[i][j]。
*/

//时间O(nk)，空间O(nk)。
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
public:
  //我们知道，动规所用的二维辅助数组可以降为一维的，即只用大小为k的一维数组记录到达第i天时的局部最优解和全局最优解。
  //需要注意的是，由于第i天时交易k次的最优解依赖于第i-1天时交易k-1次的最优解，所以数组更新应当从后往前（即从k到1）更新。
  int maxProfit(int k, vector<int> &prices) {
    int len = prices.size();
    if(len < 2) return 0;
    if(k >= len) return maxProfit2(prices);

    vector<int> local(k+1);
    vector<int> global(k+1);

    for(int i = 1; i < len; i ++){
      int diff = prices[i] - prices[i-1];

      for(int j = k; j > 0; j--){
        local[j] = max(global[j-1], local[j] + diff);
        global[j] = max(global[j], local[j]);
      }
    }
    return global[k];
  }

  int maxProfit2(vector<int> &prices){
    int maxProfit = 0;
    for(int i = 1; i< prices.size(); i ++){
      if (prices[i] > prices[i-1]) {
        maxProfit += prices[i] - prices[i-1];
      }
    }
    return maxProfit;
  }
};
//补充：这道题还有一个陷阱，就是当k大于天数时，其实就退化成 Best Time to Buy and Sell Stock II 了。
//另外，Best Time to Buy and Sell Stock III 就是本题k=2的情况，所以说IV是II和III的综合。
