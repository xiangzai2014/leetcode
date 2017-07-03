/* ****
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another
expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

******
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0) {
      return 0;
    }
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
      string s = tokens[i];
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        if (st.size() < 2) {
          return 0;
        }
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int result = 0;
        if (s == "+") {
          result = num1 + num2;
        } else if (s == "-") {
          result = num1 - num2;
        } else if (s == "*") {
          result = num1 * num2;
        } else if (s == "/") {
          result = num1 / num2;
        }

        st.push(result);
      } else {
        st.push(atoi(
            s.c_str())); //将string对象，转化为char*对象，c_str()提供了这样一种方法，它返回一个客户程序可读不可改的指向字符数组的指针
      }
    }
    return st.top();
  }
};

int main() {
  Solution s;
  string str[] = {"2", "1", "+", "3", "*"};
  vector<string> strArray(str, str + sizeof(str) / sizeof(str[0]));
  std::cout << s.evalRPN(strArray) << '\n';
  return 0;
}
