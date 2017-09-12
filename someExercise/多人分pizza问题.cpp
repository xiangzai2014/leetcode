/**
简单题意：
      有多个面积不相等的披萨，分给多个人，要求每个人拥有的披萨面积相同，并且不能重组。先输入x和y为披萨和人的个数，之后输入x个披萨的半径，
      求每个人所能拥有的最大面积。
思路：
     采用二分法，先记录所有面积的总和作为最大值，最小值为零，求中间值，然后将所有的披萨计算这个面积所能满足的人数和真实人数作比较，
     之后再用二分法的基本方法计算即可。其中最重要的是当计算满足的人数时，应该将人数类型设为整形。
**/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double pi = acos(-1.0);

int main(){
  int m, f;//pizza和人的个数
  double tmp, sum, size[10000], low, high, mid;
  sum = 0;
  cin >> m >> f;
  for(int i = 1; i <= m; i ++){
    cin >> tmp;
    size[i] = tmp*tmp*pi;
    sum += size[i];
  }

  return 0;
}
