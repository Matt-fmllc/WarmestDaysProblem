// WarmestDaysProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>



// Problem
// Given a list of daily temperaturs, T, return a list such that,
// for each day in the input, tells you how many days you would 
// have to wait until a warmer temperature.  If there is no future
// day where this is possible, put a 0 instead.
// T = { 73,74,75,71,69,62,76,73 };
// output should be
// T1= { 1,1,4,2,1,1,0,0 }
//
// Note:  length of temperatures [1..30000]
//		  temperatures range [30..100]

// Brute force approach
bool CalculateDays(int* InputArray, int* OutputArray, int iCount)
{
	for (int x = 0; x < iCount-1; x++) {
		bool bFound = false;
		for (int y = x+1; y < iCount; y++) {
			if (InputArray[x] <= InputArray[y]) {
				OutputArray[x] = y-x;
				bFound = true;
				break;
			}
		}
		if (!bFound) {
			OutputArray[x] = 0;
		}
	}
	OutputArray[iCount-1] = 0;

	return true;
}

int main()
{
	int iInputArray[] = { 73,74,75,71,69,72,76,73 };
	int iResultsArray[sizeof(iInputArray) / sizeof(int)];

	bool bRet = CalculateDays(iInputArray, iResultsArray, (sizeof(iInputArray) / sizeof(int)) );

	printf("\n Output");
	for (int x = 0; x < (sizeof(iResultsArray) / sizeof(int)); x++) {
		printf("\n %d", iResultsArray[x]);
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
