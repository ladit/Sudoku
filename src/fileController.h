#pragma once

#include "stdafx.h"

using namespace std;

class fileController {
	public:
		bool open(string outputPath);
		void write(string outputString);
		void close();

	private:
		ofstream outFile;
};