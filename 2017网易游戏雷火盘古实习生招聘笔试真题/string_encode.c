/*
 给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。
 输入描述:
 每个测试输入包含1个测试用例
 每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。


 输出描述:
 输出编码后的字符串

 输入例子1:
 AAAABCCDAA

 输出例子1:
 4A1B2C1D2A
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main() {
     char str[10000];
     while(scanf("%s", &str) != EOF){
         //printf("%s\n", str);
         if(strcmp(str, "") == 0){
             continue;
         }
         int num = 1;
         for(int i = 1; i <= strlen(str); i ++){
             if(str[i] == str[i-1]){
                 num ++;
             }else{
                 printf("%d%c", num, str[i-1]);
                 num = 1;
             }
         }
         printf("\n");
     }
     return 0;
 }
