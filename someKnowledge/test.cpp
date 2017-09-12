#include<stdio.h>
#include <math.h>

int main(){
    int c;
    char p[5] = {1,2,3};
    printf("%p\n", &c);
    printf("%p\n", p);
    printf("%p\n", p+1);
    printf("%p\n", p+2);
}
