/*求解x^5 + x^3 + 7 = 0的根*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.00001
//求x^5+x^3+7的值
double func(double x){
  return (pow(x, 5) + pow(x, 3) + 7);
}

//二分与迭代的结合
//求解y(m)和y(n)的值，并和他们的中间值y(x)的比较
//不断取中间值y=func(x),当y接近于0时，那么结束循环！此时x的值便是我们求到近似值
double calRoot(int m, int n){
  double a, b;
  double x, y, y1, y2;
  a = m;
  b = n;
  while(1){
    x = (a+b)/2;
    y = func(x);
    if(fabs(y) < eps) return x;
    y1 = func(a);
    y2 = func(b);
    if(y*y1<0) b = x;//如果y1和y为异号的话就将a,b中间值x传递给b
    if(y*y2<0) a = x;
  }
}

int main(int argc, char const *argv[]) {
  double a, b;
  a = -2;
  b = -1;
  double x = calRoot(a, b);
  printf("%lf\n", x);
  return 0;
}
