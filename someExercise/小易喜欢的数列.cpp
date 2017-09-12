/***
小易非常喜欢拥有以下性质的数列:
1、数列的长度为n
2、数列中的每个数都在1到k之间(包括1和k)
3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
例如,当n = 4, k = 7
那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。
输入描述:
输入包括两个整数n和k(1 ≤ n ≤ 10, 1 ≤ k ≤ 10^5)


输出描述:
输出一个整数,即满足要求的数列个数,因为答案可能很大,输出对1,000,000,007取模的结果。

输入例子1:
2 2

输出例子1:
3
*/
/**
动态规划 dp[i][j]表示的含义是前i个整数，以j结尾的时候，有多少喜欢的数列。
转义方程如下
dp[i][j]=sum( dp[i-1][1,2,3,…,k] ) - sum(dp[i-1][x] , x>j且 x%j=0)
解释一下方程的意思，当新增加固定一个数的时候，这个新串的种类数，就是不增加这一位时所有喜欢数列种类之和，这是总数，再减去前一位中不满足(A <= B)或(A mod B != 0)这条性质的串。
**/
#include <iostream>
#include <vector>
using namespace std;

int num = 1e9+7;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
  dp[0][1] = 1;
  for(int i = 1; i <= n; i ++){
    int sum = 0;
    for(int j= 1; j <= k; j ++){
      sum += dp[i-1][j];
      sum %= num;
    }
    for(int x = 1; x <= k; x ++){
      int sum2 = 0;
      for(int y = x + x; y <= k; y += x){
        sum2 += dp[i-1][y];
        sum2 %= num;
      }
      dp[i][x] = (sum-sum2+num) % num;
    }
  }
  int res = 0;
  for(int i = 1; i <= k; i ++){
    res += dp[n][i];
    res %= num;
  }
  cout << res << endl;
  return 0;
}
