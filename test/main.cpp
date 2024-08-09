#include "EndianTest.hpp"

bool OutputTest(bool bTestResult, const char *szDescription);

int main()
{
	return
		OutputTest(TestEndianConversionToHost(),   "Endian conversion to host endian") &&
		OutputTest(TestEndianConversionFromHost(), "Endian conversion from host endian")
		? 0 : 1;
}

#include <iostream>

bool OutputTest(bool bTestResult, const char *szDescription)
{
	if (bTestResult)
		std::cout << szDescription << ": Succeeded.\n";
	else
		std::cout << szDescription << ": Failed.\n";

	return bTestResult;
}
