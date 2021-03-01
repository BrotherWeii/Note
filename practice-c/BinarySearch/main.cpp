#include <stdio.h>
#include "BinarySearch.h"

int nAry[] = { 1,3,11,23,442,21122 };

int main()
{
	int nIndex = -1;

	//normal
	nIndex = BinarySearch(1, nAry, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);
	nIndex = BinarySearch(23, nAry, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);
	nIndex = BinarySearch(21122, nAry, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);

	//recursion
	nIndex = BinarySearchRecursion(1, nAry, 0, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);
	nIndex = BinarySearchRecursion(23, nAry, 0, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);
	nIndex = BinarySearchRecursion(21122, nAry, 0, sizeof(nAry) / sizeof(int));
	printf("The index of target in sorted array:%d", nIndex);


	return 0;
}