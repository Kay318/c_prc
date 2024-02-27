#include <iostream>
#include "Arr2.h"

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Reallocate(tArr* _pArr)
{
	int* pNew = (int*)malloc(_pArr->iMaxCount * sizeof(int) * 2);
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}
	free(_pArr->pInt);
	_pArr->pInt = pNew;
	_pArr->iMaxCount *= 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		Reallocate(_pArr);
	}

	_pArr->pInt[_pArr->iCount++] = _iData;
}

void Change(tArr* _pArr, int i)
{
	int iTemp = _pArr->pInt[i];
	_pArr->pInt[i] = _pArr->pInt[i + 1];
	_pArr->pInt[i + 1] = iTemp;
}


void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
	
}