/*
Given a string s and a dictionary of words dict, add spaces in s to construct a
sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].
A solution is["cats and dog", "cat sand dog"]
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
  vector<bool> *dp;
  vector<string> result;
  vector<string> myString;
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    dp = new vector<bool>[ s.size() ];
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        dp[i].push_back(match(s.substr(i, j - i + 1), dict));
      }
    }
    cout << dp[0][2] << dp[3][3] << endl;
    output(s.size() - 1, s);
    return result;
  }

  bool match(string s, unordered_set<string> &dict) {
    if (dict.find(s) != dict.end()) { //查找到了字符串s
      return true;
    } else {
      return false;
    }
  }

  void output(int i, string s) {
    if (i == -1) { //递归时退出的条件
      string str;
      for (int j = myString.size() - 1; j >= 0; j--) {
        str += myString[j];
        if (j != 0) {
          str += " ";
        }
      }
      result.push_back(str);
    } else {
      for (int k = 0; k <= i; k++) {
        if (dp[k][i - k]) // dp[k][i-k]:偏移为k，截断长度i-k+1
        {
          myString.push_back(s.substr(k, i - k + 1));
          output(k - 1, s);
          myString.pop_back();
        }
      }
    }
  }
};

int main() {
  string s = "catsanddog";
  unordered_set<string> dict; //= ["cat", "cats", "and", "sand", "dog"];
  dict.insert(dict.end(), "dog");
  dict.insert(dict.end(), "sand");
  dict.insert(dict.end(), "and");
  dict.insert(dict.end(), "cats");
  dict.insert(dict.end(), "cat");
  //输入测试
  for (auto i = dict.begin(); i != dict.end(); ++i)
    cout << *i << " ";
  cout << endl;

  Solution solution;
  solution.result = solution.wordBreak(s, dict);
  for (auto i = solution.result.begin(); i != solution.result.end(); ++i)
    cout << *i << " ";
  cout << endl;

  return 0;
}
