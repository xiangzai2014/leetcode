/**
题目描述

一个字符串S是偶串当且仅当S中的每一个字符都出现了偶数次。如字符串”aabccb”是一个偶串，因为字符a,b,c都出现了两次。而字符串”abbcc”不是偶串，因为字符a出现了一次。
现在给出一个长度为n的字符串T=t1,t2,t3,…,tn。字符串的子串为其中任意连续一段。T长度为1的子串有n个，长度为2的子串有n-1个，以此类推，T一共有n(n+1)/2个子串。
给定T，你能算出它有多少个子串是偶串吗？
输入
输入一个字符串T，T中只有小写字母。T的长度不超过100000。
输出
输出一个数，T的所有子串中偶串的个数。
样例输入
abbc
样例输出
1
*/

/**
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//o(n^3)
bool isEvenStr(const char* str, int len){
  for(int i = 0; i < len; i ++){
    int n = count(str, str+len, str[i]);
    if(n % 2 == 0) continue;
    else{
      return false;
    }
  }
  return true;
}

int main(){
  string T;
  while(cin >> T){
    int len = T.length();
    int cnt = 0;
    for(int i = 0; i < len; i++){
      for(int j = 1; j <= len-i; j ++){//j表示长度
        const char* str = (T.substr(i, j)).data();
        if(isEvenStr(str, j)){
          cnt ++;
        }
      }
    }
    cout << cnt << endl;
  }
}**/

#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;

char s[100001];
unordered_map<int,int> mp;
int main(){
  	scanf("%s",s);
  	char* i;
  	int t=0,res=0;
  	mp[0]=1;
  	for(i=s;*i;i++){
    	t ^= (1<<(*i-'a'));
      	res+=mp[t];
      	mp[t]++;
    }
  	printf("%d\n",res);
	return 0;
}
