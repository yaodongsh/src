#include "list.h"

ListNode* list_append(ListNode** List, Value data)
{
    ListNode* Node = malloc(sizeof(ListNode));
    ListNode* iter;
    if (Node == NULL) { 
    	return NULL;
    }
    Node->value = data;
    Node->next  = NULL;
    if(*List == NULL) { // new list
        *List = Node;
        Node->prev = NULL;
    } else {
    	for(iter=*ListNode; iter->next!=NULL; iter=iter->next) {
    		iter->next = Node;
    		Node->prev = iter;
    	}
    }
    return Node;
}