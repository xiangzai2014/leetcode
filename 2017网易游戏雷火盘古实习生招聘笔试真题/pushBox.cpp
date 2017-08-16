/*
大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。
玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，
当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。
输入描述:
每个测试输入包含1个测试用例
第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
每个地图必定包含1个玩家、1个箱子、1个目的地。


输出描述:
输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

输入例子1:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...

输出例子1:
3
11
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<vector<char>> mm;
    int m, n;
    int x, y, bx, by, tx, ty;//玩家坐标、箱子坐标、目的地坐标
    int st[10][10][10][10];//存放当前点到终点已经走过了多少步,前两个为一个坐标、后两个为一个坐标

    Solution(){}
    ~Solution(){}

public:
    bool valid(int x, int y){
        if(x >= 0 && x < m && y >= 0 && y < n && mm[x][y] != '#'){//在地图内且坐标不为障碍物
            return true;
        }
        return false;
    }

};

int main(){
    Solution s;
    while(cin >> s.m >> s.n){
      s.mm = vector<vector<char>> (s.m, vector<char> (s.n));//m*n的一个矩阵
      for(int i = 0; i < s.m; i ++){
          for(int j = 0; j < s.n; j ++){
              char t;
              cin >> t;
              if(t == 'X'){//玩家
                  s.x = i;
                  s.y = j;
              }
              if(t == '*'){//箱子
                  s.bx = i;
                  s.by = j;
              }
              if(t == '@'){//目的地
                  s.tx = i;
                  s.ty = j;
              }
              s.mm[i][j] = t;
          }
      }
      //纪录下一个状态
      vector<vector<int>> next = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};//左、右、下、上
      queue<vector<int>> que;
      for(int i = 0; i < 10; i ++){
          for(int i1 = 0; i1 < 10; i1 ++){
              for(int i2 = 0; i2 < 10; i2 ++){
                  memset(s.st[i][i1][i2], 0, 10 * sizeof(int));
                  /*for(int i3 = 0; i3 < 10; i3 ++){
                      s.st[i][i1][i2][i3] = 0;
                  }*/
              }
          }
      }
      que.push({s.x, s.y, s.bx, s.by});//玩家位置和箱子位置
      s.st[s.x][s.y][s.bx][s.by] = 1;
      while(!que.empty()){
          vector<int> t = (vector<int> &&) que.front();
          que.pop();
          s.x = t[0];
          s.y = t[1];
          s.bx = t[2];
          s.by = t[3];
          for(int i = 0; i < next.size(); i ++){
              int nx = s.x + next[i][0], ny = s.y + next[i][1];
              int nnx = nx + next[i][0], nny = ny + next[i][1];
              if(s.valid(nx, ny) && (nx!=s.bx || ny!=s.by) && s.st[nx][ny][s.bx][s.by] == 0){//判断是否到达了箱子处
                  s.st[nx][ny][s.bx][s.by] = s.st[s.x][s.y][s.bx][s.by] + 1;
                  que.push({nx, ny, s.bx, s.by});
                  continue;
              }
              else if(nx == s.bx && ny == s.by && s.valid(nnx, nny) && s.st[nx][ny][nnx][nny] == 0){//第一次执行时已经到了箱子处，人开始推着箱子前进，所以人和箱子始终是同一个方向的，接下来人换着方向去找重点
                  s.st[nx][ny][nnx][nny] = s.st[s.x][s.y][s.bx][s.by] + 1;
                  if(s.mm[nnx][nny] == '@'){
                      cout << s.st[nx][ny][nnx][nny] - 1;
                      return 0;
                  }
                  que.push({nx, ny, nnx, nny});
              }
          }
      }
    }

    cout << -1 << endl;
    return 0;
}
