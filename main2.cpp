#include <stdio.h>


int main() {

	// ������ ����
	// �ּҸ� �����ϴ� ����
	int i = 100;
	int* pInt = &i;

	// �ּҷ� ����
	*pInt = 400;
	int iSize = sizeof(pInt);

	// �ּ��� ����: 1byte
	// pInt�� int* ���� �̱� ������, ����Ű�� ���� int�� �ؼ��Ѵ�.
	// ���� �ּҰ��� 1 �����ϴ� �ǹ̴� ���� int ��ġ�� �����ϱ� ���ؼ� sizeof(int) ������ �����ϰ� �ȴ�

	// �����Ϳ� �迭
	// �迭�� Ư¡
	// 1. �޸𸮰� �������� �����̴�.
	// 2. �迭�� �̸��� �迭�� ���� �ּ��̴�.
	int iArr[10] = {};

	// int ������ ����
	*(iArr + 0) = 10;  // iArr[0] = 10;
	*(iArr + 1) = 10;  // iArr[1] = 10;


	volatile const int cint = 100;

	int* pInt2 = (int*)&cint;
	*pInt2 = 300;
	printf("cint���: %d\n", cint);


	return 0;
}