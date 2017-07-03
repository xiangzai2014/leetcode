/*Given two words (start and end), and a dictionary, find the length of shortest
transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,
Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]
As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

//主要思想：广度优先搜索。先构造一个字符串队列，并将start加入队列。1.对队列头字符串做单个字符替换
//每次替换后，2.判断是否和end匹配，如果匹配，返回答案；3.没有匹配，则在字典里面查询是否有“邻居字符串”,
//如果有，则将该字符串加入队列，同时将该字符串从字典里删除。重复1的过程，直到和end匹配。如果最后队列
//为空还未匹配到，则返回0.
class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    queue<string> Q;
    Q.push(start);
    int result = 1;
    while (!Q.empty()) {
      int qsize = Q.size(); //层次遍历，记录当前队列大小
      while (qsize--) {
        string cur_front = Q.front();
        Q.pop();
        int size = cur_front.size();
        for (int i = 0; i < size; i++) {
          char ch = cur_front[i]; //对队列头字符串每一个字符进行替换
          for (int j = 0; j < 26; j++) {
            cur_front[i] = 'a' + j; //替换字符
            if (cur_front == end)
              return result + 1;
            if (dict.find(cur_front) != dict.end()) {
              Q.push(cur_front);     //变换在字典中找到了
              dict.erase(cur_front); //从字典中删除
            }
          }
          cur_front[i] =
              ch; //还原队列头字符串，因为有可能在字典中可以找到多个“临近字符串”
        }
      }
      result++;
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  string start = "hit";
  string end = "cog";
  unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
  Solution s;
  std::cout << s.ladderLength(start, end, dict) << '\n';
  return 0;
}
