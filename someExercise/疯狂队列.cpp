/**
小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。
学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。
由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。
小易老师回来一定会气得半死。
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高


输出描述:
输出一个整数,表示n个学生列队可以获得的最大的疯狂值。

如样例所示:
当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100。
这是最大的疯狂值了。

输入例子1:
5
5 10 25 40 25

输出例子1:
100
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec;
  int tmp;
  for(int i = 0; i < n; i ++){
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());
  vector<int> vec2;
  int flag = 1, left = -1, right = n-1;
  vec2.push_back(vec[n-1]);//先把最大的数放进去
  while(left+1 < right){
    if(flag){
      //先左侧插入最小，再右侧插入次小
      vec2.insert(vec2.begin(), vec[++left]);//insert(iterator， type_define)表示在iterator所指向的位置插入数据，同时之前在iterator中的数据被推到后面的位置。不是覆盖。
      if(left+1 < right){
        vec2.push_back(vec[++left]);
      }
    }else{
      vec2.insert(vec2.begin(), vec[--right]);
      if(left+1 < right){
        vec2.push_back(vec[--right]);
      }
    }
    flag ^= 1;//保证一左一右（先左后右
  }
  if(abs(vec2[n-1] - vec2[n-2]) < abs(vec2[n-1] - vec2[0])){//最后两个数字相同
    int tmp = vec2[n-1];
    vec2.erase(vec2.end() - 1);
    vec2.insert(vec2.begin(), tmp);
  }
  int count = 0;
  for(int i = 1; i < vec2.size(); i ++){
    count += abs(vec2[i] - vec2[i-1]);
  }
  std::cout << count << '\n';
  return 0;
}
