#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// �޸� ����
// 1. ���� ����
// 2. ������ ����
// 3. �� ����
// 4. ROM(�ڵ�) ����

unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0;
	while ('\0' != _pStr[i])
	{
		++i;
	}

	return i;
}

int main2()
{
	// * �������� const�� * �տ� ������ �����Ͱ� ����Ű�� �ּ��� ���� ���� ���� ���ϰ�
	// const�� * �ڿ� ������ �����Ͱ� �����ϴ� �ּҸ� ���� ����

	// 1. const
	const int i = 100;

	// const �� ������
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// const ������
	int b = 0;
	const int* pConstInt = &a;

	pConstInt = &b;


	int* const pIntConst = &a;

	*pIntConst = 400;

	const int* const pConstIntConst = nullptr;

	int const* p = &a;
	p = &b;

	wchar_t wc =94;
	short s = 49;

	char c = 1;
	c = '1';

	wc = '2';

	{
		printf("%c", c);
	}

	char szChar[10] = "abcedf";
	wchar_t szWChar[10] = L"abcedf";
	const wchar_t* pChar = L"abcedf";

	{
		// ����
		char szTest[10] = "abc�ѱ�";

	}


	wchar_t szName[10] = L"Raimond";

	int iLen = GetLength(szName);

	wchar_t szString[100] = L"abc";

	wcscat_s(szString, 100, L"def");
	
	return 0;
}