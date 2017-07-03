/*
Given n points on a 2D plane,
find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    int size = points.size();
    if (size == 0) {
      return 0;
    } else if (size == 1) {
      return 1;
    }

    int ret = 0;
    for (int i = 0; i < size; i++) {
      int currentMax = 1;
      map<double, int> mmp;
      int vcntP = 0; //垂直点
      int dupP = 0;  //重复点
      for (int j = 0; j < size; j++) {
        if (j != i) {
          double x1 = points[i].x - points[j].x;
          double y1 = points[i].y - points[j].y;
          if (x1 == 0 && y1 == 0) {
            //重复
            dupP++;
          } else if (x1 == 0) {
            //垂直x轴
            if (vcntP == 0) {
              vcntP = 2;
            } else {
              vcntP++;
            }
            currentMax = max(vcntP, currentMax);
          } else {
            double k = y1 / x1; //斜率
            if (mmp[k] == 0) {
              mmp[k] = 2;
            } else {
              mmp[k]++;
            }
            currentMax = max(mmp[k], currentMax);
          }
        }
      }
      ret = max(ret, currentMax + dupP);
    }
    return ret;
  }
};

int main() {
  Solution s;
  vector<Point> v;
  Point p1(0, 0), p2(0, 1), p3(1, 1), p4(2, 2), p5(3, 3);
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);
  v.push_back(p5);
  cout << s.maxPoints(v) << endl;
  return 0;
}
