#pragma once


enum class NODE_TYPE
{
	PARENT,   // 0
	LCHILD,	  // 1
	RCHILD,   // 2
	END,      // 3
};

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}


template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair;
	tBSTNode*	  arrNode[(int)NODE_TYPE::END];

	tBSTNode()
		: pair()
		, arrNode{}
	{

	}

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent , _pLChild , _pRChild }
	{

	}
};


template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>*	m_pRoot;    // 루트 노드 주소
	int					m_iCount;   // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair);

	class iterator;

public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{

	}

	// iterator
	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;
		tBSTNode<T1, T2>*	m_pNode;  // null인 경우 end iterator

	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{}
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	// 첫번째 데이터라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;

			{
				if (nullptr == pNode->arrNode[(int)node_type])
				{
					pNode->arrNode[(int)node_type] = pNewNode;
					pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
					break;
				}
				else
				{
					pNode = pNode->arrNode[(int)node_type];
				}
			}
		}

	}

	// 데이터 개수 증가
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// pNode 가 현재 찾으려는 노드다.
			break;
		}

		{
			if (nullptr == pNode->arrNode[(int)node_type])
			{
				// 못찾음. pNode == nullptr ==> enditerator
				pNode = nullptr;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	return iterator(this, pNode);
}
