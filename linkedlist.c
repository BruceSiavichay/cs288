#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	char name[20];
	struct node *next;
};

int main(){
	struct node *head=NULL, *tail=NULL, *pnode;
	//pnode will be used to create new nodes in the list
	while(1){
		pnode = (struct node *)malloc(sizeof(struct node));

		printf("data: "); scanf("%d", &(pnode->data));
		printf("name: "); scanf("%s", pnode->name);

		if(pnode -> data < 0){
			break;
		}

		// ensure to set the last node pointer to NULL
		pnode -> next = NULL;

		//updating the head
		if (head == NULL){
			head = pnode;
		}

		// updating the tail
		if(tail != NULL){
			tail -> next = pnode;
		}
		tail = pnode;
	}

	//traversing a linked list
	//start from head pointer
	//proceed along the next pointer of each node
	//stop when the last node is reached
	
	pnode = head;

	while(pnode != NULL){
		printf("%d %s => ", pnode -> data, pnode -> name);
		pnode = pnode -> next;
	}

	return 0;
}
