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

// ������
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
	// ���� Ž��
	// 1. ���ĵǾ� �ִ� �����Ϳ� ���� ����

	// ����Ž��Ʈ��
	// 1. ����Ž���� ����� �� �ְ� ��ȵ� ����Ʈ��
	// 2. ������ �Է� �� Olog(N) ȿ��
	// 3. Ž�� ȿ���� Olog(N)

	// 4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	//	- �ڰ����� ��� �ʿ�(AVL, Red/Black)

	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);


	const wchar_t* pStr = L"���ڿ�";
	wchar_t szArr[100] = L"abdef";

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info));
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"ȫ�浿");

	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ã�� �� ����." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		wcout << L"���� : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����" << endl;
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