#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	//char name[20];
	struct node *next;
};

int main(){
	struct node *head=NULL, *tail=NULL, *pnode;
	int count = 1;
	while(1){
		//allocates memory for the node, not for pnode
		pnode=(struct node *)malloc(sizeof(struct node));
		printf("Input data for node %d: ", count);
		if(scanf("%d", &(pnode->data)) == EOF){
			break;
		}

		if(pnode -> data < 0) break;
		pnode -> next = NULL;
		if(head == NULL) head = pnode;
		if(tail != NULL) tail -> next = pnode;
		tail=pnode;
		count++;
	}

	printf("\n");
	printf("Data entered in the list are: \n");

	//printing in order
	pnode = head;
	while(pnode != NULL){
		printf("Data = %d \n", pnode -> data);
		pnode = pnode -> next;
	}

	pnode = head;

	
	//reverse order
	struct node *head2 = NULL, *tail2 = NULL, *pnode2, *temp;
	while(head != NULL){
		pnode2 = head;
		head = head -> next;

		pnode2 -> next = head2;
		head2 = pnode2;
	}

	pnode = head2;

	printf("The list in reverse is: \n");
	while(pnode != NULL){
                printf("Data = %d \n", pnode -> data);
		temp = pnode;
                pnode = pnode -> next;
		//using a temp node to free memory allocated node
		free(temp);
        }
	

	return 0;
}
