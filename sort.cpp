/*
一些排序算法的比较
from: https://mp.weixin.qq.com/s?__biz=MjM5NTI5NTAzNg==&mid=2656329463&idx=1&sn=ebc0d8a45e29e99d8b3024a52f72a717&chksm=bd5a44a48a2dcdb275c3774b16967d1631d08c83c0d6b37b35c5725721211ad3dca7bb6b6d60&scene=0&key=31a3a388ed6fa873afb784af993a1e5f10498ab8379957b4f3c73aea9be84f42739deff02a5490c113805ebd66ff7269ce501d1482b2c01e112c6f489bfb4cf2611dc8312e96825e5daf891dd0bc8b49&ascene=0&uin=NzMzNTE1NDQ0&devicetype=iMac+MacBookPro11%2C1+OSX+OSX+10.12.3+build(16D32)&version=12020710&nettype=WIFI&fontScale=100&pass_ticket=RFTm8r1gw0prLgztk4axX1OAPhK427GzoPwxub8juSZalcnaxpi%2B7BOmwlvaBz3O
*/
#include <iostream>
using namespace std;

//交换函数
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

//希尔排序
void shellSort(int a[], int n){
  for(int step = n/2; step > 0; step /= 2){
    for(int i = 0; i < step; i ++){
      for(int j = i + step; j < n; j += step){
        //插入排序
        int k = j, value = a[j];
        while(k >= step && a[k-step] > value){
          a[k] = a[k-step];
          k -= step;
        }
        a[k] = value;
      }
    }
  }
}
/*
以n=10的一个数组49, 38, 65, 97, 26, 13, 27, 49, 55, 4为例
第一次 gap = 10 / 2 = 5

49   38   65   97   26   13   27   49   55   4
1A                       1B
     2A                       2B
          3A                       3B
               4A                       4B
                    5A                       5B
1A,1B，2A,2B等为分组标记，数字相同的表示在同一组，大写字母表示是该组的第几个元素， 每次对同一组的数据进行直接插入排序。
即分成了五组(49, 13) (38, 27) (65, 49)  (97, 55)  (26, 4)这样每组排序后就变成了(13, 49)  (27, 38)  (49, 65)  (55, 97)  (4, 26)，下同。

第二次 gap = 5 / 2 = 2
排序后

13   27   49   55   4    49   38   65   97   26
1A        1B       1C         1D        1E
     2A        2B        2C        2D        2E

第三次 gap = 2 / 2 = 1
4   26   13   27   38    49   49   55   97   65
1A  1B   1C   1D   1E    1F   1G   1H   1I   1J

第四次 gap = 1 / 2 = 0 排序完成得到数组：
4   13   26   27   38    49   49   55   65   97
*/

//插入排序 时间复杂度o(n^2), 空间复杂度o(1)
void insertionSort(int a[], int n){
  for(int i = 1; i < n; i ++){
    int j = i, value = a[i];
    while(j > 0 && a[j-1] > value){
      a[j] = a[j-1];//后移
      j--;
    }
    a[j] = value;//插入
  }
}
//冒泡排序 时间复杂度o(n^2) 空间复杂度o(1)
void bubbleSort(int a[], int n){
  for(int i = n-1; i > 0; i --){
    for(int j = 0; j < i; j ++){
      if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
      }
    }
  }
}
//快速排序 时间复杂度O(nlogn) 空间复杂度O(logn)
void quickSort(int *a, int l, int r){
  if(l < r){
    int i = l, j = r, x = a[l];
    while(i < j){
      while(i < j && a[j] >= x){// 从右向左找第一个小于x的数
        j--;
      }
      if(i < j){
        a[i++] = a[j];
      }
      while(i < j && a[i] < x){// 从左向右找第一个大于等于x的数
        i ++;
      }
      if(i < j){
        a[j--] = a[i];
      }
    }
    a[i] = x;
    quickSort(a, l, i-1);
    quickSort(a, i+1, r);
  }
}

//堆排序 时间复杂度O(nlogn) 空间复杂度o(1)
/*图例： http://www.linuxidc.com/Linux/2015-02/113519.htm*/
/*代码：https://segmentfault.com/a/1190000002466215*/
void adjustHeap(int *arrs, int p, int len){
    int curParent = arrs[p]; //当前父节点，可能比子节点小
    int child = 2*p + 1;   //左孩子，下标从0开始
    while(child < len){     //直到没有孩子节点
        if(child+1<len && arrs[child]<arrs[child+1]){
            child++;    //较大孩子的下标（左孩子或者右孩子）
        }
        if(curParent<arrs[child]){
            arrs[p]=arrs[child];
            //没有将curParent赋值给孩子是因为还要迭代子树，
            //如果其孩子中有大的，会上移，curParent还要继续下移。
            p=child;
            child=2*p+1;
        }
        else
            break;
    }
    arrs[p]=curParent;
}


void heapSort(int *arrs, int len){
  //建立堆，从底层的父亲节点开始
  for(int i = len/2-1; i >= 0; i--){
    adjustHeap(arrs, i, len);
  }
  for(int i = len-1; i >= 0; i --){
    swap(arrs[0], arrs[i]);
    adjustHeap(arrs, 0, i);
  }
}

//归并排序 时间复杂度为 O(nlogn) 空间复杂度为 O(n)
// Function to Merge Arrays L and R into A.
void Merge(int *A, int *L, int *R, int low, int high) {
  int i, j, k;
  // i - to mark the index of left aubarray (L)
  // j - to mark the index of right sub-raay (R)
  // k - to mark the index of merged subarray (A)
  i = 0; j = 0; k =0;
  while(i < low && j < high){
    if(L[i] < R[j]){
      A[k++] = L[i++];
    }
    else{
      A[k++] = R[j++];
    }
  }
  while(i < low) A[k++] = L[i++];
  while(j < high) A[k++] = R[j++];

}
// Recursive function to sort an array of integers.
//时间复杂度为 O(nlogn) 空间复杂度为 O(n)
void mergeSort(int *A, int n){
  int mid, i, *L, *R;
  if(n<2) return;
  mid = n/2;
  // create left and right subarrays
  // mid elements (from index 0 till mid-1) should be part of left sub-array
  // and (n-mid) elements (from mid to n-1) will be part of right sub-array
  L = new int[mid];
  R = new int[n-mid];
  for(i = 0; i < mid; i ++){
    L[i] = A[i];// creating left subarray
  }
  for(int i = mid; i < n; i ++){
    R[i-mid] = A[i];// creating right subarray
  }
  mergeSort(L, mid);
  mergeSort(R, n-mid);
  Merge(A, L, R, mid, n-mid);// Merging L and R into A as sorted list.
  // the delete operations is very important
  delete [] R;
  delete [] L;
}

/*
（1）快速排序、希尔排序、归并排序、堆排序的平均时间为 O(nlogn)，其他的为 O(n*n)。
（2）快速排序、希尔排序、选择排序、堆排序不稳定，其他的稳定。
（3）经过一趟排序能够保证一个元素到达最终位置的是冒泡排序、快速排序、选择排序、堆排序。
（4）元素比较次数和原始序列无关的是选择排序、折半插入排序。
（5）排序趟数和原始序列有关的是交换类排序。
（6）直接插入排序和折半插入排序的区别是寻找插入位置的方式不同，一个是按顺序查找方式，另一个是按折半查找方式。
*/


int main(){
  int a[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
  int b[10], c[10], d[10], e[10], f[10], g[10];
  memcpy(b, a, sizeof(b));
  memcpy(c, a, sizeof(c));
  memcpy(d, a, sizeof(d));
  memcpy(e, a, sizeof(e));
  memcpy(f, a, sizeof(f));
  memcpy(g, a, sizeof(g));

  cout << "希尔排序：" << endl;

  shellSort(b, 10);
  for(int i = 0; i < 9; i ++){
    cout << b[i] << " ";
  }
  cout << b[9] << endl;

  cout << "插入排序：" << endl;
  insertionSort(c, 10);
  for(int i = 0; i < 9; i ++){
    cout << c[i] << " ";
  }
  cout << c[9] << endl;

  cout << "冒泡排序：" << endl;
  bubbleSort(d, 10);
  for(int i = 0; i < 9; i ++){
    cout << d[i] << " ";
  }
  cout << d[9] << endl;

  // 快排
  cout << "快排：" << endl;
  quickSort(e, 0, 9);
  for(int i = 0; i < 9; i ++){
    cout << e[i] << " ";
  }
  cout << e[9] << endl;

  //堆排序
  cout << "堆排序：" << endl;
  heapSort(f, 10);
  for(int i = 0; i < 9; i ++){
    cout << f[i] << " ";
  }
  cout << f[9] << endl;

  //归并排序
  cout << "归并排序：" << endl;
  heapSort(g, 10);
  for(int i = 0; i < 9; i ++){
    cout << g[i] << " ";
  }
  cout << g[9] << endl;
  return 0;
}
