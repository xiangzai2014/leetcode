/**
 题目描述

 A、B两伙马贼意外地在一片沙漠中发现了一处金矿，双方都想独占金矿，但各自的实力都不足以吞下对方，
 经过谈判后，双方同意用一个公平的方式来处理这片金矿。处理的规则如下：他们把整个金矿分成n段，由A、B开始轮流从最左端或最右端占据一段，直到分完为止。
 马贼A想提前知道他们能分到多少金子，因此请你帮忙计算他们最后各自拥有多少金子?（两伙马贼均会采取对己方有利的策略）
 输入
 测试数据包含多组输入数据。输入数据的第一行为一个正整数T(T<=20)，表示测试数据的组数。然后是T组测试数据，每组测试数据的第一行包含一个整数n，
 下一行包含n个数（n <= 500 ），表示每段金矿的含金量，保证其数值大小不超过1000。
 输出
 对于每一组测试数据，输出一行"Case #id: sc1 sc2"，表示第id组数据时马贼A分到金子数量为sc1，马贼B分到金子数量为sc2。详见样例。
 样例输入
 2
 6
 4 7 2 9 5 2
 10
 140 649 340 982 105 86 56 610 340 879
 样例输出
 Case #1: 18 11
 Case #2: 3206 981
 */

/**
 令dp[i][j]表示当前还剩的金矿是区间[i,j]时，A取得的最大收益。这个转移要考虑此时该A拿还是该B拿。
 如果该A拿，则有dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);如果该B拿，则有dp[i][j]=min(dp[i+1][j],dp[i][j-1]);,
 因为B拿哪边都不会增加A的收益，而他要使A尽量拿的小。
 那么如何判断该A拿还是该B拿呢，这就与n和区间长度的奇偶关系有关了。观察到，如果n是偶数，则区间长度是偶数时轮到A拿，否则轮到B拿，n是奇数反之。
 所以该谁拿取决于n和当前区间长度的奇偶关系。在这里因为大区间只依赖于长度比他小1的小区间，所以自底向上枚举区间长度即可。
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

//动态规划只与前面一次状态有关，可以把空间复杂度降至O(n)
//时间复杂度O(n^2) 空间复杂度O(n)
vector<int> divGold(vector<int> golds){
    int len = golds.size();
    vector<vector<int> > dp(len+1, vector<int>(len+1, 0));//dp[x][y]保存第x堆到第y堆的最优解
    //后面经常要对连续子数组求和，预先储存下来，不然时间复杂度升至O(n^3)
    //golds[0]~golds[i]的和是sum[i+1]，不是sum[i]
    vector<int> sum(len+1, 0);
    for(int i = 0; i < len; i ++){
        sum[i+1] = sum[i] + golds[i];//sum[0] = 0, sum[1] = golds[0]
        dp[i+1][i+1] = golds[i];
    }
    for(int i = 1; i < len; i ++){
        for(int j = 1; j+i <= len; j ++){
            int t_sum = sum[i+j] - sum[j-1];//j到j+i堆的总含金量
            int min_gold = min(dp[j+1][i+j], dp[j][i+j-1]);//得到取最左端或者最右端的最小含金量

            dp[j][j+i] = t_sum - min_gold;//总含金量-最小含金量=最大剩余含金量
        }
    }

    return vector<int>{dp[1][len], sum[len] - dp[1][len]};//第一个是先手最大利益
}

int main(){
    int T, n;
    while(cin >> T){
        for(int i = 0; i < T; i ++){
            cin >> n;
            int tmp;
            vector<int> golds;
            for(int i = 0; i < n; i ++){
                cin >> tmp;
                golds.push_back(tmp);
            }
            vector<int> result = divGold(golds);
            cout << "Case #" << i+1 << ": " << result[0] << " " << result[1] << endl;
        }
    }
}
