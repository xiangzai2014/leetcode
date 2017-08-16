#include<stdio.h>
#include<math.h>
#define esp 0.001

double mySqrt(double x){
  double down = 0, up, n;
  up = x;
  n = (up + down) / 2;
  if(x <= 0)
    return x;
  while ((n*n != x) && fabs(n*n - x) > esp) {
    if(n*n < x){
      down = n;
      n = (up + down) / 2;
    }else{
      up = n;
      n = (up + down) / 2;
    }
  }
  return n;
}

int main(){
  double x, res;
  scanf("%lf", &x);
  res = mySqrt(x);
  printf("%.2lf\n", res);
  return 0;
}
