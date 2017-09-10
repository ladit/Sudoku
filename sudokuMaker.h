#pragma once

#include "stdafx.h"
#include "fileController.h"

using namespace std;

class sudokuMaker {
  public:
    bool generateAndPrint(const int &sudokuQuantity);

  private:
    int	blank;  // 数独棋盘待填格数，新的待填数独棋盘模板初始化后有 72 格待填
    int	hint;  // 数独棋盘提示格数
    int fullBoard[9][9];  // 完整数独棋盘
	fileController fc;
    void newTemplate();
    bool dfs();
    int validNumbersQuantity(const int &row, const int &col, int (&mark)[10]);
};

