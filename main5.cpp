#include <iostream>



class CMy
{
private:
	int m_i;
	float m_f;

public:
	// 생성자
	// 이니셜라이져
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

	// 대입 연산자
	CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}

	// 소멸자
public:
	~CMy()
	{

	}
};


int main()
{
	// C++ 클래스 특징
	// 접근 제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨

	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달 된다.
	CMy c;
	CMy c1;
	c.SetInt(100);

	c1 = c;

	return 0;
}