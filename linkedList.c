#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int size;
	int data;
	struct Node *next;
};

struct Node* getData(struct Node *head, struct Node *current, int size);
void add(int *data, int index);
void printList(struct Node *head);
void iterateThrough(struct Node *head);

int main() {
	struct Node *head, *current;
	
	int input = -1;
	int numberOfElements = 0;
	
	bool initialized = false;
	while (input != 3) {
		if (!initialized)	
			printf("Options: initialize LinkedList [Type '0'], add to LinkedList [Type '1'], remove from LinkedList [Type '2'], or exit [Type '3'] ");
		else 	
			printf("Options: add to LinkedList [Type '1'], remove from LinkedList [Type '2'], or exit [Type '3'] ");
		scanf("%d", &input);
		if (input == 0 && !initialized) {
			initialized = true;	
			printf("how many elements do you want to add?");
			scanf("%d", &numberOfElements);
		
			printf("input data elements in the order you want them in the LinkedList");
			head = (struct Node *)malloc( sizeof(struct Node) * numberOfElements );
			current = head;
			
	
			getData(head, current, numberOfElements);
			printList(head);
		} else if (input == 1) {

			int index;		
addInput:
			printf("what index would you like to add to");
			scanf("%d", &index);
			if (head->size < 0) {
				printf("head is null");
				head = (struct Node *)malloc( sizeof(struct Node) * 1);
				head->size = 1
			} else if (head->size < index) {
				printf("choose a new index to input to - must be between 0 - %d\n", head->size);
				goto addInput;
			}
		} else if (input == 2) {
	
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
	struct Node *curr;
       	curr = head;
	int index = 0;
	while (curr->next != NULL) {
		printf("At index INDEX:%d, the data point is DATA:%d and it is located at ADDRESS:%p\n", index++, curr->data, curr);
		curr = curr->next;
	}
	printf("%d\n", curr->data);
}

void add(int *data, int index) {
//	if (index < 0 || 


}
