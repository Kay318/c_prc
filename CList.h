#pragma once

#include <assert.h>

template<typename T>
struct tListNode
{
	T             data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext;

	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

template<typename T>
class CList
{
private:
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;		
	int           m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>*	  m_pList;
		tListNode<T>* m_pNode;		// null 인 경우, end iterator 로 간주
		bool          m_bValid;

	public:
		T& operator* ()
		{
			return m_pNode->data;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator operator ++(int)
		{
			iterator copyiter(*this);

			++(*this);

			return copyiter;
		}

		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;

			return *this;
		}

		iterator operator --(int)
		{
			iterator copyiter(*this);

			--(*this);

			return copyiter;
		}

	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{

		}
		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

		friend class CList;
	};

};

template<typename T>
void CList<T>::push_back(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 함
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// 처음 입력된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상에서 입력된 경우
		// 현재 가장 마지막 데이터(tail) 를 저장하고 있는 노드와
		// 새로 생성된 노드가 서로 가리키게 한다
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// List 가 마지막 노드의 주소 값을 새로 입력된 노르도 갱신한다.
		m_pTail = pNewNode;
	}

	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);
	m_pHead->pPrev = pNewNode;
	m_pHead = pNewNode;
	
	++m_iCount;
}

template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator 가 가리키고 있는 노드의 이전으로 가서
		// 다음 노드 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator 가 가리키고 있는 노드의 이전을 새로운 노드로 지정
		// 새로운 노드의 pNext 를 iterator 가 가리키고 있는 노드로 지정
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
}

template<typename T>
CList<T>::CList()
	:m_pHead(nullptr)
	,m_pTail(nullptr)
	,m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}
