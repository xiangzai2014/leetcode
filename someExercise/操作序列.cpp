/***
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。


输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。

输入例子1:
4
1 2 3 4

输出例子1:
4 2 1 3
**/


//我们将数列从末尾元素开始，隔一个输出一个，剩下的元素从头开始顺序输出就能得到正确结果。
#include <iostream>
using namespace std;

/*** 只能AC 50%
void reverseB(int *a, int i, int j){
  if(i < j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    reverseB(a, i+1, j-1);
  }
}

int main(){
  int n, a[200000], b[200000];
  cin >> n;
  for(int i = 0; i < n; i ++){
    cin >> a[i];
    b[i] = a[i];
    reverseB(b, 0, i);
  }
  for(int i = 0; i < n-1; i ++){
    cout << b[i] << " ";
  }
  cout << b[n-1] << endl;
  return 0;
}
**/
int main(){
  int n;
  cin >> n;
  int *a = new int [n];
  for(int i = 0; i < n; i ++){
    cin >> a[i];
  }
  if(n==1){
    cout << a[0] << endl;
  }else{
    for(int i = n-1; i >= 0; i -= 2){
      cout << a[i] << " ";
    }
    int start = (n % 2);
    for(int i = start; i < n-2; i += 2){
      cout << a[i] << " ";
    }
    cout << a[n-2] << endl;
  }
  delete[] a;
  return 0;
}
