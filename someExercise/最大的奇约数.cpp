/***
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。
输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)

输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)

输入例子1:
7

输出例子1:
21
*/

/*
我们要知道当f(x)的x为奇数时，f（x）的值为其本身，当为偶数时f（x）=f（x/2），以此为递推条件。
当n为偶数时，sum（n）=f(1）+f(2)+……f(n)=sum（n/2）+ 1+3+……+n-1 = sum(n/2) + n^2 / 4;
*/
#include <iostream>
#include <math.h>
using namespace std;

long long getApproximateNumber(long long num){
  long long i;
  if(num == 1){
    return 1;
  }else if(num % 2 == 0){
    i = (num*num)/ 4;
    return getApproximateNumber(num / 2) + i;
  }else{
    return num + getApproximateNumber(num-1);
  }
}

int main(){
  long long N;
  cin >> N;

  long long  res = getApproximateNumber(N);

  cout << res << endl;
  return 0;
}
