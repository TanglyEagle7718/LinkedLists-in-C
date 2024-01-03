#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Auth: Rishi B
 */

struct Node {
	int size;
	int data;
	struct Node *next;
};

struct Node* getData(struct Node *head, struct Node *current, int size);
void add(struct Node **head, int data, int index);
int removed(struct Node **head, int index);
void printList(struct Node *head);
void iterateThrough(struct Node *head);

int main() {
	struct Node *head, *current;
	
	int input = -1;
	int numberOfElements = 0;
	
	bool initialized = false;
	while (input != 3) {
		if (!initialized)	
			printf(">> Options: initialize LinkedList [Type '0'], add to LinkedList [Type '1'], remove from LinkedList [Type '2'], or exit [Type '3'] ");
		else 	
			printf(">> Options: add to LinkedList [Type '1'], remove from LinkedList [Type '2'], or exit [Type '3'] ");
		scanf("%d", &input);
		if (input == 0 && !initialized) {
			initialized = true;	
			printf(">> how many elements do you want to add? ");
			scanf("%d", &numberOfElements);
		
			printf(">> input data elements in the order you want them in the LinkedList ");
			head = (struct Node *)malloc( sizeof(struct Node) * numberOfElements );
			current = head;
			
	
			getData(head, current, numberOfElements);
			printList(head);
		} else if (input == 1) {
			int inputC1;
			int index;		
addInput:
			printf(">> what index would you like to add to ");
			scanf("%d", &index);
			//printf("[info] The current size of LL is %d\n", head->size);
			if (head->size < 0) {
				printf("LinkedList not initialized, index can only be 0\n");
				if (index != 0)
					goto addInput;
				
				head = (struct Node *)malloc( sizeof(struct Node) * 1);
				head->size = 1;
				printf("[info]: head size has been changed to %d\n", head->size);
				printf(">> What data point would you like to add? ");
				scanf("%d",&inputC1);
				head->data=inputC1;
				initialized = true;
				printList(head);
			} else if (head->size < index) {
				printf(">> choose a new index to input to - must be between 0 - %d\n", head->size);
				goto addInput;
			} else {
				printf(">> What data would you like to add? ");
				scanf("%d", &inputC1);	
				add(&head, inputC1, index);
				printList(head);		
			}
		} else if (input == 2) {
			int index;
						
removeInput:
			printf(">> what index would you like to remove from ");
			scanf("%d", &index);
			//printf("[info] The current size of LL is %d\n", head->size);
			if (head->size < 0) {
				printf("LinkedList not initialized, initialize linked list with options [0] or [1]\n");
				
			} else if (head->size-1 < index) {
				printf(">> choose a new index to input to - must be between 0 - %d\n", (head->size-1));
				goto removeInput;
			} else {
				removed(&head, index);
				printList(head);		
			}
		}
	}
}

struct Node* getData(struct Node *head, struct Node *current, int numberOfElements) {
	int input;	
	for (int i = 0 ; i < numberOfElements ; i++) {
		
		scanf("%d", &input);

		if (i == 0) {
			current->size = numberOfElements;
		       	current->data = input;
				
		} else {
			current->next = (struct Node *)malloc( sizeof(struct Node) * 1);
			current = current->next;
			current->size = numberOfElements;
			current->data = input;
		}	
	}	

}

void printList(struct Node *head) {
	if (head->size < 0) return;
	struct Node *curr;
       	curr = head;
	int index = 0;
	while (curr->next != NULL) {
		printf("[EOP]: At index INDEX:%d, the data point is DATA:%d and it is located at ADDRESS:%p\n", index++, curr->data, curr);
		curr = curr->next;
	}

	printf("[EOP]: At index INDEX:%d, the data point is DATA:%d and it is located at ADDRESS:%p\n", index++, curr->data, curr);
	printf("[EOP]: The size of the list is %d\n", head->size);
}

void add(struct Node **head, int data, int index) {
	struct Node *curr = *head;
	if (index == curr->size) {	
		if (curr->next == NULL) {
			curr->size = curr->size + 1;
		}
		while (curr->next != NULL) {
			if (curr->size < 0) curr->size = 1;
			curr->size = curr->size + 1;
			curr = curr->next;
		}
		
		curr->next = (struct Node *)malloc( sizeof(struct Node) * 1);
		int numberOfElements = curr->size;
		curr = curr->next;
		curr->size = numberOfElements+1;
		curr->data = data;
		printf("[info]: size has been increased to %d\n", (*head)->size);
	} else if (index == 0) {
		struct Node *tmp = *head;
		struct Node *newNode = (struct Node *)malloc( sizeof(struct Node) * 1);
		newNode->size = tmp->size+1;
		newNode->data = data;
		*head = newNode;
		(*head)->next = tmp;

		printf("[info]: size has been increased to %d\n", (*head)->size);
	} else {
		for (int i = 0 ; i < index-1 ; i++) {
			curr->size = curr->size + 1;
			curr = curr->next;	
		}
		struct Node *newNode = (struct Node *)malloc( sizeof(struct Node) * 1);
		newNode->size = curr->size;
		newNode->data = data;
		newNode->next = curr->next;
		curr->next = newNode;
			
		printf("[info]: size has been increased to %d\n", (*head)->size);
	}
}


int removed(struct Node **head, int index) {
	int returnValue = -1;
	if ((*head)->size == 1) {
		returnValue = (*head)->data;
		head = NULL;
	} else if (index == 0) {
		struct Node *tmp = *head;
		(*head)->next->size = (*head)->size;
		returnValue = (*head)->data;
		*head = (*head)->next;	
		free(tmp);
		(*head)->size = (*head)->size - 1;	
	} else if (index+1 == (*head)->size) {
		struct Node *curr = *head;
		for (int i = 0 ; i < index-1 ; i++) {
			curr = curr->next;	
		}
		returnValue = curr->next->data;
		struct Node *tmp = curr->next;
		curr->next = NULL;
		free(tmp);
		(*head)->size = (*head)->size - 1;
			
	}
	return returnValue;
}
