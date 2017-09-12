/***
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。

求按从小到大的顺序的第N个丑数。

思路：某个丑数肯定是前面丑数的2,3,5倍数。只需要从前往后生成即可。1,2,3,4,5,6,8,9,10,12,15，。。。。。。。
***/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchNum(vector<int> vec, int multiplier)//数组里面的数都乘以一个数之后，返回第一个大于vec数组里面的那个数
    {
        vector<int> copyVec;
        int finanlNum = *(vec.end() - 1);
        int flagNumber = 0;
        for (auto it = vec.begin(); it < vec.end(); it++)
        {
            copyVec.push_back((*it)*multiplier);
        }
        for (auto it = copyVec.begin(); it < copyVec.end(); it++)
        {
            if (*it > finanlNum)
            {
                flagNumber = *it;
                break;
            }

        }
        return flagNumber;
    }

    int minNum(int num1, int num2, int num3)//返回三个数字里面的最小值
    {
        int minNum = num1 < num2 ? num1 : num2;
        minNum = minNum < num3 ? minNum : num3;
        return minNum;
    }

    int getUglyNumber(int index) {
        int maxNumber = 0;//记录最大丑数
        vector<int> vec;
        int i = 1;

        if (index == 0)//如果index是0，返回0
            return 0;

        while (i <= index)
        {
            if (i == 1)
                vec.push_back(i);
            else
            {
                int num1 = searchNum(vec, 2);
                int num2 = searchNum(vec, 3);
                int num3 = searchNum(vec, 5);
                int min = minNum(num1, num2, num3);
                vec.push_back(min);
            }
            i++;
        }
        maxNumber = *(vec.end() - 1);
        return maxNumber;
    }
};


int main()
{
    int N;
    Solution s;
    while (cin >> N)
    {
        cout << s.getUglyNumber(N) << endl;
    }

    return 0;
}
