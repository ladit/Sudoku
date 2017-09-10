/**
 * Use the DFS and Backtracking algorithm to generate Sudoku, base on C++.
 *
 * @author Ladit
 *
 * @functions
 *   generateAndPrint - 循环生成数独并且打印到文件
 *   newTemplate - 产生新的待填数独棋盘模板
 *   dfs - 深度优先搜索填写数独棋盘
 *   validNumbersQuantity - 某一格可填写数字数量计算
 */

#include "stdafx.h"
#include "sudokuMaker.h"

bool sudokuMaker::generateAndPrint(const int &sudokuQuantity) {
	// 生成完整数独棋盘并输出到文件
	if (fc.open(".\\sudoku.txt")) {
		for (int i = 1; i <= sudokuQuantity; i++) {
			while (true) {
				newTemplate();
				if (dfs()) {
					fc.write(fullBoard);
					break;
				}
			}
		}
		fc.close();
		return true;
	}
	return false;
}

void sudokuMaker::newTemplate() {
	srand(unsigned(time(nullptr)) + rand());
	blank = 72;
	hint = 9;
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0) {
				fullBoard[0][j] = 9-j;
			}
			else {
				fullBoard[i][j] = 0;
			}
		}
	}
	for (int i = 0, j; i < 20; i++) {
		j = (rand() * 10) % 7 + 2;
		swap(fullBoard[0][1], fullBoard[0][j]);
	}
	for (int i = 1; i < 9; i++) {
		int a = (rand() * 10) % 9;
		int b = (rand() * 10) % 9;
		if (a + b == 0) {
			i--;
			continue;
		}
		swap(fullBoard[0][i], fullBoard[a][b]);
	}
}

bool sudokuMaker::dfs() {
	if (blank == 0) {
		return true;
	}
	int minQuantity = 10;
	int mini = 0, minj = 0;
	int mark[10] = {0};

	// 寻找可填写数字数量最少的格子
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (fullBoard[i][j] != 0) {
				continue;
			}

			int count = validNumbersQuantity(i, j, mark);
			if (count == 0) {
				return false;
			}
			if (count < minQuantity) {
				minQuantity = count;
				mini = i;
				minj = j;
			}
		}
	}

	// 优先填写 可填写数字数量最少 的格子
	validNumbersQuantity(mini, minj, mark);
	for (int i = 1; i <= 9; i++) {
		if (mark[i] == 0) {
			fullBoard[mini][minj] = i;
			blank--;
			dfs();
			if (blank == 0) {
				return true;
			}
			fullBoard[mini][minj] = 0;  // 回溯法
			blank++;
		}
	}
	return true;
}

int sudokuMaker::validNumbersQuantity(const int &row, const int &col, int (&mark)[10]) {
	for (int i = 0; i < 10; i++) {
		mark[i] = 0;
	}
	for (int i = 0; i < 9; i++) {
		mark[fullBoard[i][col]] = 1;
		mark[fullBoard[row][i]] = 1;
	}
	int baseRow = row / 3 * 3;
	int baseCol = col / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mark[fullBoard[baseRow + i][baseCol + j]] = 1;
		}
	}
	int count = 0;
	for (int i = 1; i <= 9; i++) {
		if (mark[i] == 0) {
			count++;
		}
	}
	return count;
}

