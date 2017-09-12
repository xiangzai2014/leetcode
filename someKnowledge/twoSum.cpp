/***
能否快速找出一个数组中的两个数字，让这两个数字之和等于一个给定的值，为了简化起见，我们假设这个数组中肯定存在至少一组符合要求的解。
    假如有如下的两个数组，如图所示：
    5，6，1，4，7，9，8
    给定Sum= 10
    1，5，6，7，8，9
    给定Sum= 10
**/


#include <iostream>
using namespace std;

int* getSumNum(int *arr, int sum, int len){
    int i, j;
    int *pos = new int[2];
    for(i=0, j=len-1; i < j; ){
        if(arr[i] + arr[j] == sum){
            pos[0] = i;
            pos[1] = j;
            return pos;
        }else if(arr[i] + arr[j] < sum){
            i ++;
        }else{
            j --;
        }
    }
    pos[0] = -1;
    pos[1] = -1;
    return pos;
}

int main(){
    int arr[] = {5, 6, 1, 4, 7, 9, 8};
    int sum = 10;
    int *res;
    sort(arr, arr+7);
    res = getSumNum(arr, sum, 7);
    for(int i = 0; i < 2; i ++){
        cout << res[i] << " ";
    }
    cout << endl;
    delete res;
    return 0;
}
