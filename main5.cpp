#include <iostream>



class CMy
{
private:
	int m_i;
	float m_f;

public:
	// ������
	// �̴ϼȶ�����
	CMy()
		: m_i(100)
		, m_f(0.f)
	{
	}

public:
	void SetInt(int i)
	{
		this->m_i = i;
	}

	// ���� ������
	CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}

	// �Ҹ���
public:
	~CMy()
	{

	}
};


int main()
{
	// C++ Ŭ���� Ư¡
	// ���� ���� ������
	// Ŭ���� ���� ������� or ����Լ��� ���� ����

	// ������, �Ҹ���
	// ��ü ����, �Ҹ� �� �ڵ����� ȣ��
	// ���� ������ ������ �⺻ ������, �⺻ �Ҹ��ڰ� �������

	// ����Լ�
	// �ش� Ŭ������ ����ϴ� ���� �Լ�
	// �ش� Ŭ������ ��ü�� �ʿ���
	// ����Լ��� ��ü�� ���ؼ� ȣ���ϸ�, �ش� ��ü�� �ּҰ� this �����ͷ� ���� �ȴ�.
	CMy c;
	CMy c1;
	c.SetInt(100);

	c1 = c;

	return 0;
}