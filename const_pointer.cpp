#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역
// 3. 힙 영역
// 4. ROM(코드) 영역

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
	// * 기준으로 const가 * 앞에 있으면 포인터가 가리키는 주소의 변수 값을 변경 못하고
	// const가 * 뒤에 있으면 포인터가 지목하는 주소를 변경 못함

	// 1. const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// const 포인터
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
		// 문자
		char szTest[10] = "abc한글";

	}


	wchar_t szName[10] = L"Raimond";

	int iLen = GetLength(szName);

	wchar_t szString[100] = L"abc";

	wcscat_s(szString, 100, L"def");
	
	return 0;
}