/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent(临近的) numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11(i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//关键思路就是：
//到达下一层的某个点，有通过上一层的俩条路径。
class Solution {
public:
    //自顶向下
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> res(triangle.size(), triangle[0][0]);
        for(int i = 1; i < triangle.size(); i ++){
            for(int j = i; j >= 0; j --){
                if(j==0){
                    res[0] += triangle[i][j];
                }
                else if(j==i){
                    res[j] = res[j-1] + triangle[i][j];
                }
                else{
                    res[j] = triangle[i][j] + min(res[j-1], res[j]);
                }
            }
        }
        return *min_element(res.begin(), res.end());//最小元素
    }
};//运行时间：0ms 占用内存：496k

int main(){
    int arr1[] = {2};
    int arr2[] = {3, 4};
    int arr3[] = {6, 5, 7};
    int arr4[] = {4, 1, 8, 3};
    vector<int> v1(&arr1[0], &arr1[1]);
    vector<int> v2(&arr2[0], &arr2[2]);
    vector<int> v3(&arr3[0], &arr3[3]);
    vector<int> v4(&arr4[0], &arr4[4]);
    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vector<int> temp_vv;
    for(vector<vector<int> >::iterator it = vv.begin(); it != vv.end(); it++){
        temp_vv = *it;
        for(vector<int>::iterator ite = temp_vv.begin(); ite != temp_vv.end(); ite ++){
            cout << *ite << " ";
        }
        cout << '\n';
    }
    Solution s;
    cout << s.minimumTotal(vv) << endl;
    return 0;
}
