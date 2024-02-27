#pragma once

#include <assert.h>

template<typename T>
class CArr
{
private:
	T*  m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _iData);
	void resize(int _iDataCount);
	int size() { return m_iCount; };
	T& operator[](int idx);

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

	void clear()
	{
		m_iCount = 0;
	}

public:
	CArr();
	~CArr();

	// inner Ŭ������ �����ϰ� �ִ� Ŭ������ private ����� ���� ����
	class iterator
	{
	private:
		CArr* m_pArr;  // iterator�� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T* m_pData;    // �����͵��� ���� �ּ�
		int m_iIdx;    // ����Ű�� �������� �ε���
		bool m_bValid; // iterator ��ȿ�� üũ

	public:
		T& operator * ()
		{
			// iterator�� �˰� �ִ� �ּҿ�, ���� �迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		// ���� ������
		iterator& operator ++()
		{
		    // 2. end iterator �� ���
			// 3. iterator�� �˰� �ִ� �ּҿ�, ���� �迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			// 1. iterator�� ������ �����͸� ����Ű�� �ִ� ���
			// --> end iterator�� �ȴ�.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ����
		iterator operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		iterator& operator --()
		{
			return *this;
		}

		// �� ������ ==, != 
		bool operator == (const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}

			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{
		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)
		{
			if (nullptr != _pArr && 0 <= _iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

		friend class CArr;
	};
};


template<typename T>
void CArr<T>::push_back(const T& _iData)
{
	int i = 0;

	if (m_iMaxCount <= m_iCount)
	{
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _iData;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	T* pNew = new T[_iResizeCount];
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	delete[] m_pData;
	m_pData = pNew;
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// ������ ����Ű�� iterator �� ���� ��ȯ����
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);		// �����Ͱ� ���� ���, begin() == end()
	else
		return iterator(this, m_pData, 0);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_pData, -1);	
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// iterator �� �ٸ� Arr �� ��Ҹ� ����Ű�� ���
	// iterator �� end iterator �� ���
	if (this != _iter.m_pArr || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	};

	// iterator �� ����Ű�� �����͸� �迭 ������ �����Ѵ�.
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);
	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}

	_iter.m_bValid = false;

	// ī��Ʈ ����
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx);
}
