#include "CArr.h"
#include <iostream>


template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// C++ ���� �Ҵ� new, delete

	CArr<int> carr;
	carr.push_back(10);
	carr.push_back(20);

	int iData = carr[1];
	carr[1] = 100;
	printf("%d, %d, %d", iData, carr[0], carr[1]);

	// �Լ� ���ø�
	int i = Add<int>(10, 20);

	return 0;
}