//typedef void (*Fun) (void) 的理解——函数指针——typedef函数指针

//函数指针的形式：
//1.返回类型(*函数名)(参数表)
#include <iostream>
using namespace std;

//定义一个函数指针pFUN，它指向一个返回类型为char，有一个整型的参数的函数
char (*pFun)(int);
//定义一个返回类型为char，参数为int的函数
//从指针层面上理解该函数，即函数的函数名实际上是一个指针，
//该指针指向函数在内存中的首地址
char glFun(int a)
{
    cout << a;
    return a;
}

int main()
{
  //将函数glFun的地址赋值给变量pFun
    pFun = glFun;
    //*pFun”显然是取pFun所指向地址的内容，当然也就是取出了函数glFun()的内容，然后给定参数为2。
    (*pFun)(2);
    return 0;
}

//而typedef可以让函数指针更直观方便
//2. typedef  返回类型(*新类型)(参数表)
/*
typedef char (*PTRFUN)(int);
PTRFUN pFun;
char glFun(int a){ return;}
void main()
{
    pFun = glFun;
    (*pFun)(2);
}
*/
