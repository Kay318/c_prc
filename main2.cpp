#include <stdio.h>


int main() {

	// 포인터 변수
	// 주소를 저장하는 변수
	int i = 100;
	int* pInt = &i;

	// 주소로 접근
	*pInt = 400;
	int iSize = sizeof(pInt);

	// 주소의 단위: 1byte
	// pInt는 int* 변수 이기 때문에, 가리키는 곳을 int로 해석한다.
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가하게 된다

	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.
	int iArr[10] = {};

	// int 단위로 접근
	*(iArr + 0) = 10;  // iArr[0] = 10;
	*(iArr + 1) = 10;  // iArr[1] = 10;


	volatile const int cint = 100;

	int* pInt2 = (int*)&cint;
	*pInt2 = 300;
	printf("cint출력: %d\n", cint);


	return 0;
}