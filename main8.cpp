#include <iostream>

#include <map>
#include <set>

#include <string>

#include "CBST.h"

using std::map;
using std::make_pair;

using std::set;

using std::wcout;
using std::endl;

using std::wstring;

#define MAN		1
#define WOMAN	2

// 열거형
enum MY_TYPE
{
	TYPE_1,  // 0
	TYPE_2,  // 1
	TYPE_3,  // 2
	TYPE_5 = 100,
	TYPE_6,  // 101
};

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{
	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

int main()
{
	// 이진 탐색
	// 1. 정렬되어 있는 데이터에 적용 가능

	// 이진탐색트리
	// 1. 이진탐색을 사용할 수 있게 고안된 이진트리
	// 2. 데이터 입력 시 Olog(N) 효율
	// 3. 탐색 효율은 Olog(N)

	// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	//	- 자가균형 기능 필요(AVL, Red/Black)

	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);


	const wchar_t* pStr = L"문자열";
	wchar_t szArr[100] = L"abdef";

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"홍길동");

	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없음." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}

	map<wstring, tStdInfo> mapStdInfo;

	wstring str;
	str = L"abcedf";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	wstring str2;
	
	if (str < str2)
	{

	}
	
	CBST<int, int> bstint;

	bstint.insert(make_bstpair(100, 0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));

	CBST<int, int>::iterator Iter = bstint.begin();

	Iter = bstint.find(150);

	return 0;
}