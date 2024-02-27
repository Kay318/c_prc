#pragma once


typedef struct _tagArr
{
	int* pInt;
	int	 iCount;
	int  iMaxCount;
}tArr;

// 단축키 Ctrl + .
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);