#include <stdio.h>
#include <stdlib.h>

#include "Singly_Linked_List.c"

int main()
{
	Node* list = NULL;
	
	insertAtBeg(&list, 10);
	insertAtEnd(&list, 20);
	insertAtEnd(&list, 30);
	insertAtBeg(&list, 40);
	insertAfter(&list, 35, 30);
	insertBefore(&list, 25, 30);
	deleteEnd(&list);
	
//	deleteAfter(&list, 40);
	
	traverse(&list);
	
	printf("\nCount : %d", countNodes(&list));
	
//	printf("\nSearch : %d", searchNode(&list, 40)->data);
	
	return 0;
}
