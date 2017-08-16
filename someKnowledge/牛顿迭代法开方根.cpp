/*牛顿迭代法开方*/
#include<stdio.h>
#define AC 0.001

float mySqrt(float a){
  float x = 1;
  float t = x*x -a;
  while (t > AC || t < -AC) {
    x = (x + a/x) / 2;
    t = x*x - a;
  }
  return x;
}

int main(){
  float a, res;
  scanf("%f", &a);
  res = mySqrt(a);
  printf("%f\n", res);
  return 0;
}
