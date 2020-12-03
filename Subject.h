#pragma once
#include "Definitions.h"


//Receiver class
class Subject {

public:

	int f1() {
		return 24;
	}

	int f2(int param1) {
		return param1 * 5;
	}

	int f3(int param1, int param2) {
		return param1 - param2;
	}

};