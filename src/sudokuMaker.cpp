/**
 * Use the DFS and Backtracking algorithm to generate Sudoku, base on C++.
 *
 * @author Ladit
 *
 * @functions
 *   sudokuMaker - 构造函数
 *   generate - 生成数独
 *   echo - 输出数独
 *   newTemplate - 产生新的待填数独棋盘模板
 *   dfs - 深度优先搜索填写数独棋盘
 *   validNumbersQuantity - 某一格可填写数字数量计算
 */

#include "stdafx.h"
#include "sudokuMaker.h"

const vector< vector<int> > emptyBoard = vector< vector<int> >(9, vector<int>(9, 0));
const int seedNumbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

sudokuMaker::sudokuMaker() {
  blank = 72;
  hint = 9;
  vector< vector<int> > fullBoard = emptyBoard;
  vector< vector<int> > partialBoard = emptyBoard;
}

void sudokuMaker::generate() {
	// 生成完整数独棋盘
	while (true) {
		newTemplate();
		if (dfs()) {
			partialBoard = fullBoard;
			break;
		}
	}

	// 生成挖空后的数独棋盘
	hint = 18;
	blank = 81 - hint;
	for (int i = 1; i <= blank; i++) {
		int a = (rand() * 10) % 9;
		int b = (rand() * 10) % 9;
		if (partialBoard[a][b] != 0) {
			partialBoard[a][b] = 0;
		}
		else {
			i--;
		}
	}
}

void sudokuMaker::echo() {
	cout << "fullBoard:" << endl;
	cout << "---------" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << fullBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------" << endl << endl;
	cout << "partialBoard:" << endl;
	cout << "---------" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << partialBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------" << endl;
}

void sudokuMaker::newTemplate() {
	srand((unsigned)time(NULL));

	fullBoard = emptyBoard;
	vector<int> randRow(seedNumbers, seedNumbers + 9);
	fullBoard[0] = randRow;
	for (int i = 0, j; i < 20; i++) {
		j = (rand() * 10) % 8 + 1;
		swap(fullBoard[0][0], fullBoard[0][j]);
	}
	for (int i = 0; i < 9; i++) {
		int a = (rand() * 10) % 9;
		int b = (rand() * 10) % 9;
		swap(fullBoard[0][i], fullBoard[a][b]);
	}
}

bool sudokuMaker::dfs() {
	if (blank == 0) {
		return true;
	}
	int minQuantity = 10;
	int mini = 0, minj = 0;

	vector<int> mark(10, 0);

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

int sudokuMaker::validNumbersQuantity(const int row, const int col, vector<int> &mark) {
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

