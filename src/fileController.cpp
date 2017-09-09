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

bool fileController::open(string outputPath) {
	outFile.open(outputPath, ios::out | ios::trunc);
	if (outFile.good()) {
		return true;
	}
	return false;
}

void fileController::write(string outputString) {
	if (outFile.is_open()) {
		outFile << outputString;
	}
}

void fileController::close() {
	outFile.close();
}