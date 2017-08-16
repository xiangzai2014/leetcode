/**
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1

输入例子1:
4 24

输出例子1:
5

**/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void calDivisors(int K, vector<int> &divisors){
    for(int i = 2; i <= sqrt(K); i ++){
        if(K % i == 0){
            divisors.push_back(i);
            if(K / i != i){//非平方时另一个数也要加入
                divisors.push_back(K / i);
            }
        }
    }
}

int jump(int N, int M){
    vector<int> res(M+1, 0);
    res[N] = 1;
    for(int i = N; i < M; i ++){
        vector<int> divisors;//所有约数
        if(res[i] == 0) continue;//位置不能到达，跳过
        calDivisors(i, divisors);//位置i时所有能走的步数
        for(int j = 0; j < divisors.size(); j ++){//记录从起点N到位置i的最小步数
            if(i + divisors[j] <= M){
                if(res[divisors[j] + i] == 0){
                    res[divisors[j] + i] = res[i] + 1;//到达位置i的最小步数加1
                }else{ //其它点也能到达，比较大小，记录最小步数
                    res[divisors[j] + i] = (res[i] + 1)<res[divisors[j] + i] ? (res[i] + 1): res[divisors[j] + i];
                }
            }
        }

    }
    if(res[M] == 0)
        return -1;
    else
        return res[M]-1;
}

int main(){
    int N, M;
    cin >> N >> M;
    int step = jump(N, M);
    cout << step << endl;
    return 0;
}
