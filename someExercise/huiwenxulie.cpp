/**
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列,
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述:
输出一个数，表示最少需要的转换次数

输入例子1:
4
1 1 1 3

输出例子1:
2
**/

//利用递归，两端不论怎样都要相等或者最终合成为同一个数
#include<iostream>
using namespace std;

int comb(int *nums, int head, int tail){
    int times = 0;
    int left = nums[head], right = nums[tail];
    while(head < tail && left != right){
        if(left < right){
            left += nums[++head];
            times ++;
        }else{
            right += nums[--tail];
            times ++;
        }
    }
    if(head >= tail) return times;
    else{
        return times += comb(nums, ++head, --tail);
    }
}

int main(){
    int nums[51];
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    cout << comb(nums, 0, n-1) << endl;
    return 0;
}

/**
#include <iostream>
#include <vector>
using namespace std;
 
int fun(vector<int> arr) {
    int rslt = 0;
    int n = arr.size();
    if (n <= 1) {
        return 0;
    }
    int l = 0;
    int r = n - 1;
    int ln = arr[l];
    int rn = arr[r];
    while (l < r) {
        if (ln < rn) {
            ln += arr[++l];
            ++rslt;
        }
        else if (ln > rn) {
            rn += arr[--r];
            ++rslt;
        }
        else {
            ++l;
            --r;
            ln = arr[l];
            rn = arr[r];
        }
 
    }
 
    return rslt;
}
 
int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << fun(arr);
    }
 
    return 0;
}
**/
