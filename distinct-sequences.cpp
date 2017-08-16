/*
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative positions of
the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).
Here is an example:
S ="rabbbit", T ="rabbit"
Return 3.
*/
#include <iostream>
using namespace std;
#include <string>
#include <vector>

//f(i , j ) 表示T[0,j] 在S[0，i] 中的匹配个数
//如果不使用S[i] , 那么f(i , j) = f(i-1 , j)
//如果使用了s[i] , 那么一定有 S[i] == T[j] , f( i , j ) = f(i -1 , j -1 )
//f( i , j ) = f( i -1 , j ) +　f(i - 1 , j - 1);
//降维后代码如下
//参考《leetcode题解》
class Solution {
public:
    int numDistinct(string S, string T) {
      vector<int> f(T.length() + 1);
      f[0] = 1;
      for(int i = 0 ; i < S.length() ; i++){
        for(int j = T.length() -1; j >= 0; j--){
          if(T[j] == S[i]){
            f[j + 1] += f[j];
          }
        }
      }
      return f[T.length()];
    }
};//运行时间：1ms 占用内存：496k

int main(){
  string S = "rabbbit";
  string T = "dd";
  Solution s;
  int num = s.numDistinct(S, T);
  cout << num << endl;
  return 0;
}
