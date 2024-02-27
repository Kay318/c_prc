#include <stdio.h>

#define MAX_SIZE 20
#define HUNGRY     0x001
#define THIRSTY    0x002
#define TIRED      0x004
#define COLD	   0x008

#define POISION1   0x010
#define POISION2   0x020
#define POISION3   0x040
#define POISION4   0x080

#define POISION5   0x100
#define POISION6   0x200
#define POISION7   0x400
#define POISION8   0x800

// 주석

int add(int left, int right)
{
	return left + right;
}


int main()
{
	// 자료형 (크기 단위, byte)
	// 정수형 : char(1), wchar(2), short(2), int(4), long(4), long long(8)
	// 실수형 : float(4), double(8)

	int i = 0;
	unsigned char c = 0;

	int data = 20;
	data = 10 / 3;

	int size = MAX_SIZE;

	unsigned int iStatus = 0;

	// 상태 추가
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	// 상태 체크
	if (iStatus & THIRSTY) {

	}

	// 특정 자리 비트 제거
	iStatus &= ~THIRSTY;

	// 함수
	data = add(10, 20);

	for (int i = 0; i < 10; ++i)
	{
		printf("Output test\n");
	}


	while (i < 10)
	{
		printf("Output test\n");
		++i;
	}

	int iInput = 0;
	scanf_s("%d", &iInput);

	return 0;
}

// 단축키
// 주석: Ctrl + k, c
// 주석 해제: Ctrl + k, u
// alt drag
// 
// 중단점: F9
// 디버깅 종료하기: shift + f5