/**
* Use the DFS and Backtracking algorithm to generate Sudoku, base on C++.
*
* @author Ladit
*
* @functions
*   check - 检查输入
*   checkStringAndConvertToInteger - 检查字符串并转换成整数
*/

#include "stdafx.h"
#include "usageValidator.h"

int usageValidator::check(int argc, char **argv) {
	if (argc == 1) {
		string sudokuQuantityString;
		cout << "Please input the number of Sudoku: ";
		cin >> sudokuQuantityString;
		return checkStringAndConvertToInteger(sudokuQuantityString);
	}
	else if (argc == 3) {
		string parameter2 = argv[1];
		string parameter3 = argv[2];
		if (parameter2 == "-c" || parameter2 == "-C") {
			return checkStringAndConvertToInteger(parameter3);
		}
	}
	return 0;
}

int usageValidator::checkStringAndConvertToInteger(const string &str) {
	size_t sizeOfString = str.size();
	for (size_t i = 0; i < sizeOfString; i++) {
		int temp = int(str[i]);
		if (temp >= 48 && temp <= 57) {
			continue;
		}
		else {
			return 0;
		}
	}
	int convertedInteger = stoi(str);
	if (convertedInteger <= 0 || convertedInteger > 1000000) {
		return 0;
	}
	return convertedInteger;
}


