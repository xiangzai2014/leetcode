/*
Given a string s and a dictionary of words dict, determine if s can be segmented
into a space-separated sequence of one or more dictionary words.
For example, given
s ="leetcode",
dict =["leet", "code"].
Return true because"leetcode"can be segmented as"leet code".
*/

#include <algorithm>
#include <functional> //greater<int>()!!!
#include <iostream>
#include <list>
#include <map>
#include <numeric> //accmulate
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    int len = s.length();
    std::vector<bool> dp(len + 1, false); // dp[i]表示以i结尾的是否能够满足条件
    dp[0] = true;
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] == true && dict.find(s.substr(j, i - j)) != dict.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[len];
  }
};

int main() {
  string s = "leetcode233";
  unordered_set<string> dict;
  dict.insert(dict.end(), "233");
  dict.insert(dict.end(), "code");
  dict.insert(dict.end(), "leet");

  //输入测试
  for (auto i = dict.begin(); i != dict.end(); ++i)
    cout << *i << " ";
  cout << endl;

  Solution solution;
  bool result = solution.wordBreak(s, dict);
  cout << result << endl;

  return 0;
}
