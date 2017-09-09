#pragma once

#include "stdafx.h"

using namespace std;

class sudokuMaker {
  public:
    sudokuMaker();
    void generate();
    void echo();

  private:
    int	blank;  // 数独棋盘待填格数，新的待填数独棋盘模板初始化后有 72 格待填
    int	hint;  // 数独棋盘提示格数
    vector< vector<int> > fullBoard;  // 完整数独棋盘
    vector< vector<int> > partialBoard;  // 挖空后的数独棋盘
    void newTemplate();
    bool dfs();
    int validNumbersQuantity(const int row, const int col, vector<int> &mark);
};

