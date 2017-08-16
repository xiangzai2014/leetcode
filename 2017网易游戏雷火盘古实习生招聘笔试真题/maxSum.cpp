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
#include <iostream>
using namespace std;

class Solution{
public:
    int sideNum;//N
    int addTimes;//D
    int maxSum;

    Solution():maxSum(0){}
    ~Solution(){}

public:
    void rowAdd(int **p, int i, int j){
        int result = 0;
        for(int k = 0; k < addTimes; k ++){
            result += p[i][j+k];
        }
        if(result > maxSum) maxSum = result;
    }

    void lineAdd(int **p, int i, int j){
        int result = 0;
        for(int k = 0; k < addTimes; k ++){
            result += p[i+k][j];
        }
        if(result > maxSum){
            maxSum = result;
        }
    }

    void leftUpToRightDownAdd(int **p, int i, int j){
        int result = 0;
        for(int k = 0; k < addTimes; k ++){
            result = result + p[i+k][j+k];
        }
        if(result > maxSum){
            maxSum = result;
        }
    }

    void rightUpToLeftDownAdd(int **p, int i, int j){
        int result = 0;
        for(int k = 0; k < addTimes; k ++){
            result = result + p[i+k][j-k];
        }
        if(result > maxSum){
            maxSum = result;
        }
    }
};

int main(){
    Solution s;
    while(cin >> s.sideNum >> s.addTimes){
        int flagNum = s.sideNum - s.addTimes;
        int **ptr = new int*[s.sideNum];
        for(int i = 0; i < s.sideNum; i ++){
            ptr[i] = new int[s.sideNum];
        }

        for(int i = 0; i < s.sideNum; i ++){
            for(int j = 0; j < s.sideNum; j ++){
                cin >> ptr[i][j];
            }
        }

        for(int i = 0; i < s.sideNum; i ++){
            for(int j = 0; j < s.sideNum; j ++){
                if(j <= flagNum){
                    s.rowAdd(ptr, i, j);
                }
                if(i <= flagNum){
                    s.lineAdd(ptr, i, j);
                }
                if(j<= flagNum && i <= flagNum){
                    s.leftUpToRightDownAdd(ptr, i, j);
                }
                if(i <= flagNum && j >= (s.addTimes-1)){
                    s.rightUpToLeftDownAdd(ptr, i, j);
                }
            }
        }

        cout << s.maxSum << endl;
    }
    return 0;
}
