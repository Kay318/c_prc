#pragma once

#include <iostream>

typedef struct _tagArr
{
	int* pInt;
	int  iCount;
	int  iMaxCount;
}tArr;


void InitArr(tArr* _pArr);
void ReleaseArr(tArr* _pArr);
void PushBack(tArr* _pArr, int iData);
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));