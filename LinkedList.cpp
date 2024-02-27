#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	if (nullptr == _pList->pHeadNode)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode)
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}

		pCurFinalNode->pNextNode = pNode;
	}
	

	++_pList->iCount;

}

void PushFront(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	_pList->pHeadNode = pNode;
	
	++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pNode = _pList->pHeadNode;
	while (pNode->pNextNode)
	{
		tNode* pNext = pNode->pNextNode;
		free(pNode);
		pNode = pNext;
	}
}
