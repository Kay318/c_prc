#include <iostream>


using std::cout;
using std::endl;


class CParent
{
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

public:
	CParent()
		: m_i(0)
	{
		cout << "何葛 积己磊" << endl;
	}
	~CParent()
	{
		cout << "何葛 积己磊" << endl;
	}
};


class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

public:
	CChild()
		: m_f(0.f)
	{
		cout << "磊侥 积己磊" << endl;
	}

	~CChild()
	{
		cout << "磊侥 积己磊" << endl;
	}
};


int main()
{
	CParent parent;
	CChild child;

	parent.SetInt(10);
	child.SetInt(20);

	return 0;
}