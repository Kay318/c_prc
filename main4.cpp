#include <iostream>
#include "LinkedList.h"


int main()
{
	tLinkedList list = {};
	InitList(&list);
	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);
	PushFront(&list, 400);

	ReleaseList(&list);


	return 0;
}