/***
活动安排问题就是要在所给的活动集合中选出最大的相容活动子集合，是可以用贪心算法有效求解的很好例子。该问题要求高效地安排一系列争用某一公共资源的活动。
贪心算法提供了一个简单、漂亮的方法使得尽可能多的活动能兼容地使用公共资源。
设有n个活动的集合E={1,2,…,n}，其中每个活动都要求使用同一资源，如演讲会场等，而在同一时间内只有一个活动能使用这一资源。
每个活动i都有一个要求使用该资源的起始时间si和一个结束时间fi,且si <fi 。如果选择了活动i，则它在半开时间区间[si, fi)内占用资源。
若区间[si, fi)与区间[sj, fj)不相交，则称活动i与活动j是相容的。也就是说，当si≥fj或sj≥fi时，活动i与活动j相容。
要在所给的活动集合中选出最大的相容活动子集合。
***/
#include <iostream>
using namespace std;

void outputResult(int *a_r, int n){
  for(int i = 0; i < n; i ++){
    if(a_r[i] == 1){
      cout << "活动" << i+1 << "被安排~" << endl;
    }
  }
}

void greedySelect(int *a1, int *a2, int *a_r, int n){
  int last_choose = 0;
  a_r[0] = 1;
  for(int i = 1; i < n; i ++){
    if(a1[i] >= a2[last_choose]){
      a_r[i] = 1;
      last_choose = i;
    }
  }
}

int main(int argc, char const *argv[]) {
  int act_start[] = {1, 3, 0, 6, 3, 5, 6, 8, 8, 2, 12};
  int act_finish[11] = {4,5,6,7,8,9,10,11,12,13,14};
  int act_res[11] = {0};
  greedySelect(act_start, act_finish, act_res, 11);
  outputResult(act_res, 11);

  return 0;
}

/***
由于输入的活动以其完成时间的非减序排列，所以算法greedySelector每次总是选择具有最早完成时间的相容活动加入集合A中。
直观上，按这种方法选择相容活动为未安排活动留下尽可能多的时间。也就是说，该算法的贪心选择的意义是使剩余的可安排时间段极大化，以便安排尽可能多的相容活动。
算法greedySelector的效率极高。
当输入的活动已按结束时间的非减序排列，算法只需O(n)的时间安排n个活动，使最多的活动能相容地使用公共资源。如果所给出的活动未按非减序排列，可以用O(nlogn)的时间重排。
***/
