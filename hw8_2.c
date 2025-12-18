#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        //char name[20];
        struct node *next;
};

int main(){
        struct node *head=NULL, *tail=NULL, *pnode;
        int count = 0;
        while(1){
                //allocates memory for the node, not for pnode
                pnode=(struct node *)malloc(sizeof(struct node));
                //printf("Input data for node %d: ", count);
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

	//check necessary in case there's 0 or 1 node before sorting
	if(head && head -> next){
		for(int i = 0; i < count; i++){
                	struct node *curr = head, *curr2 = head -> next, *prev = NULL;
                	for(int j = 0; j < count - 1; j++){
                        	if(curr -> data > curr2 -> data){
					//curr node gets attached to the one after its next node
                                	curr -> next = curr -> next -> next;
					//the one after curr gets placed before curr
                                	curr2 -> next = curr;

                                	if(prev){
						//the one before curr would get attached to the curr2 now, completing the order
                                        	prev -> next = curr2;
                                	}else{
						//if theres no prev that means we are at first node so curr2 becomes new head
                                        	head = curr2;
                                	}
					prev = curr2;
                                	curr2 = curr -> next;
                        	}else{
                                	prev = curr;
                                	curr = curr -> next;
                                	curr2 = curr2 -> next;
                        	}
                	}
                curr = head;
                curr2 = head;
                curr2 = curr2 -> next;
        	}
	}

	pnode = head;
        while(pnode != NULL){
                printf("%d \n", pnode -> data);
                pnode = pnode -> next;
        }


        return 0;
}         
