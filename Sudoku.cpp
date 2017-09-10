/**
 * Use the DFS and Backtracking algorithm to generate Sudoku, base on C++.
 *
 * @author Ladit
 * @functions
 *   main - 主函数
 */

#include "stdafx.h"
#include "sudokuMaker.h"
#include "usageValidator.h"

using namespace std;

// 使用方式
const string usage = "\nUsage:\n  1.Directly run to input the number of Sudoku;\n  2.\"sudoku -c N\", N (0 < N <= 1000000, integer) is the number of Sudoku.\n\n";
int sudokuQuantity = 0;

int main(int argc, char *argv[]) {
	usageValidator uv;
	sudokuQuantity = uv.check(argc, argv);
	if (!sudokuQuantity) {
		cout << usage;
		return 0;
	}
	sudokuMaker sudoku;
	if (sudoku.generateAndPrint(sudokuQuantity)) {
		cout << "\nCompeleted!\n\n";
	}
	else {
		cout << "\nFile open error!\n\n";
	}
	system("pause");
	return 0;
}

