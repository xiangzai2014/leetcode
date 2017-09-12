/***
Given an array S of n integers,
are there elements a, b, c in S such
that a + b + c =
0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
翻译： 给一个数组。找出其中3个数字等于0的组合。 按升序排列。

思路：这道题和前些天刷的Two Sum 原理差不多。只不过是Two Sum的和是前一个数字的相反数。还有一个问题就是，如果当前数字和下一个数字重复，应该排除这些重复，不遍历，减少复杂度。
***/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > twoSum(int *num, int start, int length, int target){
  vector<vector<int> > res;
  if(num==NULL || length < 2){
    return res;
  }
  int l = start;
  int pri = start-1;//当前数字
  int r = length-1;
  while(l < r){
    if(num[l] + num[r] == target){
      vector<int> adjust;
      adjust.push_back(num[pri]);
      adjust.push_back(num[l]);
      adjust.push_back(num[r]);
      res.push_back(adjust);
      //跳过重复
      int k = l + 1;//跳过左重复
      while(k < r && num[k] == num[l]){
        k ++;
      }
      l = k;
      k = r -1;//跳过右重复
      while(k > l && num[k] == num[r]){
        k --;
      }
      r = k;
    }else if(num[l] + num[r] > target){
      r--;
    }else{
      l++;
    }
  }
  return res;
}

vector<vector<vector<int> > > threeSum(int *num, int length){
  vector<vector<vector<int> > > res;
  if(num == NULL || length < 3){
    return res;
  }
  sort(num, num+length);
  for(int i = 0; i < length-2; i ++){// 保证最后得有num.length-1 和num.length-2两个数，才可以进循环
    if(i > 0 && num[i] == num[i-1]){//跳过重复
      continue;
    }
    vector<vector<int> > cur = twoSum(num, i+1, length, -num[i]);
    res.push_back(cur);
  }
  return res;
}

int main(){
  int arr[] = {1, 5, -2, -3, 6, 8, -7, -2, 10};
  vector<vector<vector<int> > > res = threeSum(arr, 9);
  /*
  for(int i = 0; i < res.size(); i ++){
    for(int j = 0; j < res[i].size(); j ++){
      for(int k = 0; k < res[i][j].size(); k ++){
        cout << res[i][j][k] << " ";
      }
      cout << endl;
    }
  }
  */

  for(vector<vector<vector<int> > >::iterator iter1 = res.begin(); iter1 != res.end(); iter1 ++){
    for(vector<vector<int> >::iterator iter2 = iter1->begin(); iter2 != iter1->end(); iter2 ++){
      for(vector<int>::iterator iter3 = iter2->begin(); iter3 != iter2->end(); iter3 ++){
        cout << *iter3 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
