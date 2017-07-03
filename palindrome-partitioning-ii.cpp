/*Given a string s, partition s such that every substring of the partition is a
palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s ="aab",
Return1since the palindrome partitioning["aa","b"]could be produced using 1
cut.*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

/*
class Solution {
public:
  // i为下标，j为偏移量。若[i-j, i+j]段为回文串， 则 cut[i+j+1] =
  // min(cut[i+j+1], cut[i-j] + 1)
  int minCut(string s) {
    int n = s.size();
    if (n == 0) {
      return 0;
    }
    vector<int> cut(n + 1, n);
    cut[0] = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j];
           j++) { //奇
        cut[i + j + 1] = min(cut[i + j + 1], cut[i - j] + 1);
      }
      for (int j = 0; i - j - 1 >= 0 && i + j < n && s[i - j - 1] == s[i + j];
           j++) { //偶
        cut[i + j + 1] = min(cut[i + j + 1], cut[i - j - 1] + 1);
      }
    }
    return cut[n];
  }
};
*/

/*
另一种方法：动态规划，时间复杂度o(n^2)
dp[i]代表子串s[0~i-1]的最小切割数，dp[i] = min(dp[j] +
1),其中子串s[j~i-1]是回文(0<=j<=i-1)，dp[s.length()]就是解。
*/
class Solution {
public:
  int minCut(string s) {
    int len = s.length();
    // 用于描述s.substr(k, j - k+1) 是否能构成回文子串的矩阵
    // flag[k][j] = true -> s中下标为k到j的子串能构成回文子串
    vector<vector<bool>> flag(len, vector<bool>(len, false));
    // 用于记录最佳分割次数的vector
    // 初始状态下，长为i的子串的最佳分割次数为：vec[i] = i-1
    vector<int> vec(len + 1);
    for (int i = 0; i < len + 1; i++) {
      vec[i] = i - 1;
    }
    //进入动态规划
    for (int i = 0; i < len; i++) {
      for (int j = 0; j <= i; j++) {
        // s中的s[j]到s[i]构成的子串（substr(j,i-j+1)）能不能构成回文串？
        if (s[i] == s[j] &&
            (i - j < 2 ||
             flag[j + 1][i - 1] == true)) { // flag[j+1][i-1]之前能够算出来
          flag[j][i] = true;
          //此时前i个字符的最佳分割或者为原分割次数vec[i+1]，或为前j-1个字符的最佳分割次数+1
          vec[i + 1] = min(vec[i + 1], vec[j] + 1);
        }
      }
    }
    return vec[len];
  }
};

int main() {
  string s = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostp"
             "qczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucx"
             "pobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohz"
             "nkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhg"
             "xukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlg"
             "nfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfw"
             "hxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnw"
             "wqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp"; //对应输出452
  Solution solution;
  cout << solution.minCut(s) << endl;
  return 0;
}
