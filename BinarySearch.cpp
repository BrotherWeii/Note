// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int BinarySearch(int nKey, const int* pArray, int nArraySize);

int main()
{

	//整数溢出案例，输出结果-512695411
	int nA = 3333333333333333333;
	int nB = 8888888888888888888;
	int nTemp = (nA + nB) >> 1;
	std::cout << nA + nB << std::endl;
	std::cout << nTemp << std::endl;

	int a[] = {0,1, 2,3,5,12,33,44,213,432,1234,12322 };
	std::cout << BinarySearch(5, a, sizeof(a)/sizeof(int));
}

int BinarySearch(int nKey, const int* pArray, int nArraySize)
{
	if (pArray)
	{
		//确定数组序号区间[nL,nR]，nMid
		int nL = 0;
		int nR = nArraySize -1;
		int nMid = nL + (nR - nL) >> 1 ;
		//int nMid = （nL + nR）/2；两个整数相加，可能出现整数溢出

		while (nL <= nR)
		{
			if (nKey == pArray[nMid]) return nMid;
			else if (nKey > pArray[nMid]) nL = nMid + 1;
			else if (nKey < pArray[nMid]) nR = nMid - 1;
	
			nMid = nL + (nR - nL) / 2;
		}
	}

	return -1;
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
