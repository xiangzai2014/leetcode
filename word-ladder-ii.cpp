/*Given two words (start and end), and a dictionary, find all shortest
transformation sequence(s) from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,
Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> res;
  vector<string> tmp_path;
  void generate(map<string, vector<string>> &path, string start, string end) {
    tmp_path.push_back(start);
    if (start == end) {
      reverse(tmp_path.begin(), tmp_path.end());
      res.push_back(tmp_path);
      reverse(tmp_path.begin(), tmp_path.end());
      return;
    }
    for (int i = 0; i < path[start].size(); i++) {
      generate(path, path[start][i], end);
      tmp_path.pop_back();
    }
  }

  vector<vector<string>> findLadders(string start, string end,
                                     unordered_set<string> &dict) {
    unordered_set<string> current, next;
    map<string, vector<string>> path;
    if (dict.count(start) > 0) { //词典中有start 则去掉
      dict.erase(start);
    }
    current.insert(start);
    for (; !current.count(end) && !dict.empty();) {
      for (auto per = current.begin(); per != current.end(); per++) {
        string tmp;
        for (int i = 0; i < start.size(); i++) {
          tmp = *per;
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (tmp[i] == ch)
              continue;
            tmp[i] = ch;
            if (dict.count(tmp)) {
              path[tmp].push_back(*per);
              next.insert(tmp);
            }
          }
        }
      }
      if (next.empty()) {
        break;
      }
      for (auto each = next.begin(); each != next.end(); each++) {
        dict.erase(*each);
      }
      current = next;
      next.clear();
    }
    generate(path, end, start);
    return res;
  }
};
