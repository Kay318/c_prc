#pragma once


typedef struct _tagArr
{
	int* pInt;
	int	 iCount;
	int  iMaxCount;
}tArr;

// ����Ű Ctrl + .
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);