#include <iostream>
#include <vector>
#include <list>

#include "CList.h"
// #include "CArr.h"

namespace MYSPACE
{
	int g_int;
}

namespace OTHERSPACE
{
	int g_int;
}

// using namespace MYSPACE;
using std::cout;
using std::endl;
using std::vector;
using std::list;

class CTest
{
public:
	int m_i;

public:
	CTest& operator = (const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

//public:
//	CTest()
//		: m_i(0)
//	{
//
//	}
//
//	CTest(const CTest& _other)
//		: m_i(_other.m_i)
//	{
//
//	}

};

void MyEndL()
{
	wprintf(L"\n");
}

class CMyOStream
{
public:
	CMyOStream& operator<< (int _iData)
	{
		wprintf(L"%d", _iData);
		return *this;
	}

	CMyOStream& operator<< (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}

	CMyOStream& operator >> (int& _iData)
	{
		scanf_s("%d", &_iData);
		return *this;
	}

	CMyOStream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

};

CMyOStream mycout;

int main()
{
	//CList<int> list;

	//for (int i = 0; i < 4; ++i)
	//{
	//	list.push_back(i);
	//}

	//// C printf
	//std::cout << "안녕" << 10 << std::endl;

	//// C scanf
	//int iInput = 0;
	//std::cin >> iInput;

	//MYSPACE::g_int = 0;
	//OTHERSPACE::g_int = 0;



	//setlocale(LC_ALL, "korean");
	//_wsetlocale(LC_ALL, L"korean");

	//mycout << 20 << 30 << L"중국어" << MyEndL;
	//mycout << L"한글";

	//int a;
	//mycout >> a;

	//vector<int> vecInt;
	//vecInt.push_back(10);
	//vecInt.push_back(20);

	//vecInt[0] = 100;
	//vecInt.at(0);
	//vecInt.data();
	//vecInt.size();
	//vecInt.capacity();

	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}


	//list<int> listInt;
	//listInt.push_back(10);
	//listInt.push_front(100);
	//listInt.size();

	//// iterator(inner class)
	//list<int>::iterator iter = listInt.begin();
	//int iData = *iter;
	//++iter;

	//CArr<int> myvector;

	//myvector.push_back(10);
	//myvector.push_back(20);
	//myvector.push_back(30);


	//CArr<int>::iterator myiter = myvector.begin();
	//// int iValue = *myiter;
	//// *myiter = 100;

	//myiter = myvector.erase(myiter);
	//

	//for (myiter = myvector.begin(); myiter != myvector.end(); ++myiter)
	//{
	//	cout << *myiter << endl;
 //	}

	//myiter = myvector.begin();

	//// int iData = *(++myiter);
	//int iData = *(myiter++);

	//CTest t1;
	//t1.m_i = 100;

	//CTest t2(t1);
	//CTest t3 = t1;  // 복사생성자가 호출

	//
	//// vector::erase
	//vector<int> vecInt;

	//vecInt.push_back(100);
	//vecInt.push_back(200);
	//vecInt.push_back(300);
	//vecInt.push_back(400);

	//vector<int>::iterator veciter = vecInt.begin();
	//vecInt.erase(veciter);

	//vecInt.clear();

	//// 1 ~ 10dmf qorxjdp dlqfur
	//for (int i = 0; i < 10; ++i)
	//{
	//	vecInt.push_back(i + 1);
	//}

	//veciter = vecInt.begin();
	//for (; veciter != vecInt.end(); )
	//{
	//	if (0 == *veciter % 2)
	//	{
	//		// 제거
	//		veciter = vecInt.erase(veciter);
	//	}
	//	else
	//	{
	//		++veciter;
	//	}
	//}

	//for (int i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}



	// ==============
	// list iterator
	// ==============
	CList<int> mylist;

	mylist.push_back(100);
	mylist.push_back(300);
	mylist.push_back(400);

	CList<int>::iterator listiter = mylist.begin();
	++listiter;

	listiter = mylist.insert(listiter, 200);

	for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
	{
		cout << *listiter << endl;
	}
	return 0;
}