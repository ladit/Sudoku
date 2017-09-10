#pragma once

#include "stdafx.h"

using namespace std;

class fileController {
	public:
		bool open(const string &outputPath);
		void write(int (&fullBoard)[9][9]);
		void close();

	private:
		ofstream outFile;
};