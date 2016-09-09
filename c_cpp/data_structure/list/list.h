#ifndef LIST_H
#define LIST_H
#endif

/* A doubly-linked list */

typedef void* Value;

struct _ListNode
{
	Value data;
	ListNode* prev;
	ListNode* next;
};

typedef _ListNode ListNode;

//Function List
//insert in the end of list
//parameter: pointer to the head (** means we can change the head when insert first value); value
//return value: append entry
ListNode* list_append(ListNode** List, Value data);