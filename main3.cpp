#include <iostream>
#include <time.h>

#include "Arr2.h"



void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하면 정렬하지 않음
	if (_iCount <= 1)
		return;

	while (true)
	{
		bool bFinish = true;

		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;
				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}

}


int main()
{
	int iArr[10] = { 2,1032,6,2,7,2,87 };
	BubbleSort(iArr, 10);

	tArr s = {};
	InitArr(&s);

	srand(time(nullptr));
	 
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s, iRand);
	}

	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	Sort(&s, &BubbleSort);

	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);


	// 연결형 리스트



	return 0;
}