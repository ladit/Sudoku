// Sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


using namespace std;

const int seedNumbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
const vector< vector<int> > emptyBoard = vector< vector<int> >(9, vector<int>(9, 0));

// 使用方式
const string usage = "\nUsage:\n  1.Directly run to input the number of Sudoku;\n  2.\"sudoku -c N\", N (0 < N <= 1000000, integer) is the number of Sudoku.\n\n";

int sudokuQuantity = 0;

class SudokuMaker {
public:
	void generate();  // 生成数独
	void echo();  // 输出数独

private:
	int	blank = 72;  // 数独棋盘待填格数，新的待填数独棋盘模板初始化后有 72 格待填
	int	hint = 9;  // 数独棋盘提示格数
	vector< vector<int> > fullBoard = emptyBoard;  // 完整数独棋盘
	vector< vector<int> > partialBoard = emptyBoard;  // 挖空后的数独棋盘
	void newTemplate();  // 产生新的待填数独棋盘模板
	bool dfs();  // 深度优先搜索填写数独棋盘
	int validNumbersQuantity(const int row, const int col, vector<int> &mark);  // 某一格可填写数字数量计算
};

void SudokuMaker::newTemplate() {
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

void SudokuMaker::generate() {
	// 生成数独
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

bool SudokuMaker::dfs() {
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

int SudokuMaker::validNumbersQuantity(const int row, const int col, vector<int> &mark) {
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

void SudokuMaker::echo() {
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

bool isInteger(const string &str) {
	int sizeOfString = str.size();
	for (int i = 0; i < sizeOfString; i++) {
		int temp = (int)str[i];
		if (temp >= 48 && temp <= 57) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int checkStringAndConvertToInteger(const string &str) {
	if (isInteger(str)) {
		int convertedInteger = stoi(str);
		if (convertedInteger > 0 && convertedInteger <= 1000000) {
			return convertedInteger;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	// 程序使用方式限定
	if (argc == 1) {
		string sudokuQuantityString;
		cout << "Please input the number of Sudoku:" << endl;
		cin >> sudokuQuantityString;
		int convertedInteger = checkStringAndConvertToInteger(sudokuQuantityString);
		if (convertedInteger) {
			sudokuQuantity = convertedInteger;
		}
		else {
			cout << usage;
			return 0;
		}
	}
	else if (argc == 3) {
		string parameter2 = argv[1];
		string parameter3 = argv[2];
		if (parameter2 == "-c" || parameter2 == "-C") {
			int convertedInteger = checkStringAndConvertToInteger(parameter3);
			if (convertedInteger) {
				sudokuQuantity = convertedInteger;
			}
			else {
				cout << usage;
				return 0;
			}
		}
		else {
			cout << usage;
			return 0;
		}
	}
	else {
		cout << usage;
		return 0;
	}

	SudokuMaker sudoku;
	sudoku.generate();
	sudoku.echo();
	return 0;
}