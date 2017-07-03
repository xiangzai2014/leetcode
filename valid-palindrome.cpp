/*Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama"is a palindrome.
"race a car"is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask
during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
      //非英文字母或者数字直接跳过
      while (i < j &&
             !isalnum(s[i])) { // isalnum() 用来判断一个字符是否为英文字母或数字
        i++;
      }
      while (i < j && !isalnum(s[j])) {
        j--;
      }
      if (i < j && tolower(s[i]) != tolower(s[j])) {
        return false;
      }
    }
    return true;
  }
};
