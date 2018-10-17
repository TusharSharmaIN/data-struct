#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

Node* getNode(int data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	
	n->data = data;
	n->next = NULL;
	
	return n;
}

void traverse(Node **head)
{
	Node* ptr = *head;
	
	while(ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

int countNodes(Node **head)
{
	int count = 0;
	
	Node* ptr = *head;
	
	while(ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

Node* searchNode(Node **head, int key)
{
	Node* result = NULL;
	Node* ptr = *head;
	
	while(ptr)
	{
		if(ptr->data == key)
		{
			result = ptr;
		}	
		ptr = ptr->next;
	}
	return result;
}

void insertAtBeg(Node **head, int data)
{
	Node* newNode = getNode(data);
	
	newNode->next = *head;
	*head = newNode;
	
}

void insertAtEnd(Node **head, int data)
{
	Node* newNode = getNode(data);
	
	Node* ptr = *head;
	
	if(ptr == NULL)
	{
		(*head)=newNode;
	}
	else
	{
		while(ptr->next)
		{
			ptr = ptr->next;
		}
		
		ptr->next = newNode;
	}
	
}

void insertAfter(Node **head, int data, int num)
{
	Node* newNode = getNode(data);
	
	Node* ptr = *head;
	Node* prev = ptr;
	
	if(ptr->data == num)				//condition if want to append after first elt
	{
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	else
	{
		while(prev->data != num)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = newNode;
		newNode->next = ptr;
	}		
}

void insertBefore(Node **head, int data, int num)
{
	Node* newNode = getNode(data);
	
	Node* ptr = *head;

	if(ptr->data == num)				//condition if want to append before first elt
	{
		insertAtBeg(head, data);
	}
	else
	{
		Node* prev = ptr;
		
		while(ptr->data != num)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = newNode;
		newNode->next = ptr;
	}
}

void deleteBeg(Node** head)
{
	if(*head == NULL)
		printf("\nUnder Flow");
	else
	{
		Node* ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}

void deleteEnd(Node** head)
{
	if(*head == NULL)
		printf("Under Flow");
	else
	{
		
		if((*head)->next == NULL)
		{
			deleteBeg(head);
		}
		else
		{
			Node* ptr = *head;
			Node* prev = ptr;
			
			while(ptr->next)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = NULL;
			free(ptr);
		}		
	}
}

void deleteAfter(Node** head, int num)
{
	if(*head == NULL)
	{
		printf("Under Flow");
	}
	else
	{
		Node* ptr = *head;

		if(ptr->data == num)
		{
			Node* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);	
		}
		else
		{
			Node* prev = ptr;
			
			while(prev->data != num)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			Node* temp = ptr;
			prev->next = ptr->next;
			
			free(temp); 
		}
	}
}
