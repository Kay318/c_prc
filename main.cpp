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

// �ּ�

int add(int left, int right)
{
	return left + right;
}


int main()
{
	// �ڷ��� (ũ�� ����, byte)
	// ������ : char(1), wchar(2), short(2), int(4), long(4), long long(8)
	// �Ǽ��� : float(4), double(8)

	int i = 0;
	unsigned char c = 0;

	int data = 20;
	data = 10 / 3;

	int size = MAX_SIZE;

	unsigned int iStatus = 0;

	// ���� �߰�
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	// ���� üũ
	if (iStatus & THIRSTY) {

	}

	// Ư�� �ڸ� ��Ʈ ����
	iStatus &= ~THIRSTY;

	// �Լ�
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

// ����Ű
// �ּ�: Ctrl + k, c
// �ּ� ����: Ctrl + k, u
// alt drag
// 
// �ߴ���: F9
// ����� �����ϱ�: shift + f5