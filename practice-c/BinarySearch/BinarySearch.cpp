#include "BinarySearch.h"


int BinarySearch(int nTarget, int nArray[], int nSize)
{
	if (!nArray || !(nSize > 0))
		return -1;

	int nL = 0;
	int nMid = 0;
	int nR = nSize - 1;

	while (nL <= nR)
	{
		nMid = nL + (nR - nL) / 2;

		if (nTarget > nArray[nMid]) nL = nMid + 1;
		else if (nTarget < nArray[nMid]) nR = nMid - 1;
		else return nMid;		
	}

	return -1;
}

int BinarySearchRecursion( int nTarget, int nArray[], int nLow, int nHigh )
{
	if (nLow > nHigh)
		return -1;

	int nMid = nLow + (nHigh - nLow) / 2;

	if (nTarget > nArray[nMid])
		return BinarySearchRecursion(nTarget, nArray, nMid + 1, nHigh);
	else if (nTarget < nArray[nMid])
		return BinarySearchRecursion(nTarget, nArray, nLow, nMid - 1);
	else 
		return nMid;

	return -1;
}
