/*
Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.
A region is captured by flipping all'O's into'X's in that surrounded region .
For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
首先判断“边框”两行两列的O，并深度遍历与其邻接的点O，将其都设为一个*标志；
然后将所有的O设为X，最后将设为*标志的恢复成O。（这一步顺序不可颠倒噢）
*/

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if (board.size() < 1 || board[0].size() < 1)
      return;
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) {
      dfs(board, i, 0);
      dfs(board, i, col - 1);
    }
    for (int j = 0; j < col; j++) {
      dfs(board, 0, j);
      dfs(board, row - 1, j);
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == '*')
          board[i][j] = 'O';
      }
    }
  }

  void dfs(vector<vector<char>> &board, int row, int col) {
    if (board[row][col] == 'O') {
      board[row][col] = '*';
      if (row < board.size() - 1)
        dfs(board, row + 1, col);
      if (col < board[0].size() - 1)
        dfs(board, row, col + 1);
      if (row > 1)
        dfs(board, row - 1, col);
      if (col > 1)
        dfs(board, row, col - 1);
    }
  }
};
