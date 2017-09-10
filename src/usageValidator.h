#pragma once

#include "stdafx.h"

using namespace std;

class usageValidator {
	public:
		int check(int argc, char **argv);

	private:
		int checkStringAndConvertToInteger(const string &str);
};

