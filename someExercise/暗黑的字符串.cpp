/***
一个只包含'A'、'B'和'C'的字符串，如果存在某一段长度为3的连续子串中恰好'A'、'B'和'C'各有一个，那么这个字符串就是纯净的，否则这个字符串就是暗黑的。例如：
BAACAACCBAAA 连续子串"CBA"中包含了'A','B','C'各一个，所以是纯净的字符串
AABBCCAABB 不存在一个长度为3的连续子串包含'A','B','C',所以是暗黑的字符串
你的任务就是计算出长度为n的字符串(只包含'A'、'B'和'C')，有多少个是暗黑的字符串。
输入描述:
输入一个整数n，表示字符串长度(1 ≤ n ≤ 30)


输出描述:
输出一个整数表示有多少个暗黑字符串

输入例子1:
2
3

输出例子1:
9
21
***/

//动态规划
/***
在本题中要求出长度为n的暗黑串个数，我们假设只与长度n-1的暗黑串有关，从前一个往后扩展一位，就需要从ABC中选一个进行扩展，
而要保证暗黑串，必然要考虑n-1状态时，结尾两个字符的值，当然只有相同和不同两种情况，
有：f(n-1)=s(n-1)+d(n-1)(公式一)
1.如果结尾字符相同（用s(n-1)表示），那么要组成暗黑串，扩展位可以是ABC中的任意一种，即共有3*s(n-1)种；
2.如果结尾字符不同（用d(n-1)表示），那么要组成暗黑串，扩展位只可以是前两位的一种，一共有2*d(n-1)种；
得出公式：f(n)=3*s(n-1)+2*d(n-1)（公式二）,
根据公式一，有f(n)=2*f(n-1)+s(n-1)(公式三)，
再看第一种情形，在3*s(n-1)中只有一种是保证n状态时，结尾两个字符相同,比如n-1的状态是AA,那么只有扩展位为A时，满足条件;
再看第二种情形，在2*d(n-1)中只有一种是保证n状态时，结尾两个字符不同，比如n-1的状态时AB,那么只有扩展位为A时，满足条件 ；
即有s(n)=s(n-1)+d(n-1);(公式四)
最后由公式一、三、四可得，f(n)=2*f(n-1)+f(n-2),即为状态转移公式，算法如下：
**/
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    vector<long> v(n+1, 0);
    v[1] = 3;
    v[2] = 9;
    for(int i = 3; i <= n; i ++){
      v[i] = 2*v[i-1] + v[i-2];
    }
    cout << v[n] << endl;
  }
  return 0;
}
