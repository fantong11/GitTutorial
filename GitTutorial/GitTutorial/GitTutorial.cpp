#include "pch.h"
#include <string>
#include <iostream>
using namespace System;
bool Guess(int number) {
	return false;
}
int main(cli::array<System::String ^> ^args)
{
	int guess;
	do {
		std::cin >> guess;
	} while (!Guess(guess));
	return 0;
}
