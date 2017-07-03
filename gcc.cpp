#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main() {
  // int i = 3;
  // cout << ++i << ++i;
  // printf("%d,%d", ++i, ++i);//5 5
  // int j = 1;
  // printf("%d,%d", j += 2, j *= 3); // 5 5

  int a = -1;
  unsigned b = 1;
  std::cout << "int*unsigned=" << a * b << '\n';
  std::cout << typeid(42ULL).name() << std::endl;

  cout << "列表初始化的形式(c++11)：" << '\n';
  int units_sold = 0;
  int units_sold1 = {0};
  int units_sold3{0};
  int units_sold2(0);
  cout << units_sold << " " << units_sold1 << " " << units_sold2 << " "
       << units_sold3 << '\n';

  cout << "vector测试：" << endl;
  /*根据1) 2)的结果,可以想到,在1)中,
  往a向量中压入的是b的值,即a[0]=b,此时a[0]和b是存储在两个不同的地址中的.
  因此改变b的值不会影响a[0];而在2)中,因为是把一个地址(指针)压入向量a,即a[0]=b,因此释放了b的地址也就释放了a[0]的地址,
  因此a[0]数组中存放的数值也就不得而知了.
  */
  // 1)
  vector<int> aVector0;
  int bVector0 = 5;
  aVector0.push_back(bVector0);
  // 2)
  vector<int *> aVector;
  int *bVector;
  bVector = new int[4];
  bVector[0] = 0;
  bVector[1] = 1;
  bVector[2] = 2;
  aVector.push_back(bVector);
  delete bVector; //释放b的地址空间
  for (int i = 0; i < 3; i++) {
    cout << aVector[0][i] << endl;
  }

  return 0;
}
