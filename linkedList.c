#include <stdio.h>
#include <stdlib.h>


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
		
	printf("Options: initialize LinkedList [Type '0'], add to LinkedList [Type '1'], remove from LinkedList [Type '2']  ");
	int input;
	scanf("%d", &input);
	if (input == 0) {
	
		int numberOfElements;
		printf("how many elements do you want to add?");
		scanf("%d", &numberOfElements);
	
		printf("input data elements in the order you want them in the LinkedList");
		head = (struct Node *)malloc( sizeof(struct Node) * numberOfElements );
		current = head;
			
	
		getData(head, current, numberOfElements);
		printList(head);
	} else if (input == 1) {
	
	} else if (input == 2) {
	
	}
	iterateThrough(head);	

}

void iterateThrough(struct Node *head) {
	
	int index = 0;
	while (head->next != NULL) {
		printf("At index INDEX:%d, the data point is DATA:%d and it is located at ADDRESS:%p\n", index++, head->data, head);
		head = head->next;
	}
	printf("%d\n", head->data);
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