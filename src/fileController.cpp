/**
* Use the DFS and Backtracking algorithm to generate Sudoku, base on C++.
*
* @author Ladit
*
* @functions
*   open - 打开文件以输出
*   write - 写入
*   close - 关闭文件
*/

#include "stdafx.h"
#include "fileController.h"

bool fileController::open(const string &outputPath) {
	outFile.open(outputPath, ios::out | ios::trunc);
	if (outFile.good()) {
		return true;
	}
	return false;
}

void fileController::write(int(&fullBoard)[9][9]) {
	string fullBoardString;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fullBoardString += char(fullBoard[i][j] + '0');
			if (j != 8) {
				fullBoardString += " ";
			}
		}
		fullBoardString += "\n";
	}
	fullBoardString += "\n";
	outFile << fullBoardString;
}

void fileController::close() {
	outFile.close();
}