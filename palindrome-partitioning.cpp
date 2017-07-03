/*Given a string s, partition s such that every substring of the partition is a
palindrome(回文).
Return all possible palindrome partitioning of s.
For example, given s ="aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void dfs(string s, vector<string> &path, vector<vector<string>> &res) {
    if (s.size() < 1) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < s.size(); i++) {
      int begin = 0;
      int end = i;
      while (begin < end) {
        if (s[begin] == s[end]) {
          begin++;
          end--;
        } else {
          break;
        }
      }
      if (begin >= end) {
        path.push_back(s.substr(0, i + 1));
        dfs(s.substr(i + 1), path, res);
        path.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    dfs(s, path, res);
    return res;
  }
};

int main(int argc, char const *argv[]) {
  string s = "aab";
  Solution sol;
  vector<vector<string>> res = sol.partition(s);
  for (int m = 0; m < res.size(); m++) {
    for (int n = 0; n < res[m].size(); n++) {
      cout << res[m][n] << " ";
    }
  }
  cout << '\n';
  return 0;
}
