#include <math.h>
#include <stdio.h>
#define N 3 //系数矩阵的尺寸

void Solve(double A[][N], double b[100], int size, double eps) {
  //各个参数分别表示系数矩阵、y值矩阵、系数矩阵大小、精度
  double x[100] = {0};   //第k+1次迭代的结果
  double xx[100] = {0};  //第k次迭代的结果
  int Max = 100;         //最大迭代次数
  double residual = 0.0; //
  double sum = 0.0;
  double dis = 0.0;
  double dif = 1.0; //相邻迭代的结果差
  for (int k = 1; (k < Max) && (dif > eps); k++) {
    dif = 0.0;
    printf("\n第%d次迭代的结果：\n", k);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i != j) {
          sum += A[i][j] * xx[j];
        }
      }
      x[i] = (b[i] - sum) / A[i][i];
      sum = 0.0;
    }
    residual = 0.0;
    //计算相邻迭代的结果
    for (int m = 0; m < size; m++) {
      dis = fabs(x[m] - xx[m]);
      if (dis > residual)
        residual = dis;
    }
    dif = residual;
    //打印第k次的结果
    for (int i = 0; i < size; i++) {
      printf("%12.8f ", x[i]);
      xx[i] = x[i];
    }
    printf("\n与上次计算结果的距离:%12.8f \n", dif);
  }
  printf("\n迭代计算的结果为：\n");
  for (int k = 0; k < size; k++) {
    printf("%12.8f ", xx[k]);
  }
  printf("\n");
  return;
}

int main(void) {
  double A[N][N] = {{5, -1, -1}, {-1, 5, -1}, {-1, -1, 5}};
  double b[N] = {1, 2, 1};
  double eps = 1.0e-4; //精度
  Solve(A, b, N, eps);
  return 0;
}
