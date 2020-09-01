#define SIZE_NODE (struct Node*)malloc(sizeof(struct Node))

#include <stdio.h>
#include <stdlib.h>

//Each element in linked list is a type of Node
//One node is connected with another node py the pointer next Node
struct Node {
	int data;
	struct Node* next;
};



//A function to print all nodes after passed to function node
//To print the entiry list pass head node
//Argument: node
void print_list(struct Node* current) {
	if(current == NULL) return;
	
	printf("%d", current->data);
	
	if(current->next) {
		printf(" -> ");
		print_list(current->next);
	}
}


//A function to insert node before head(if you pass head, or before given node)
//Arguments: data, node
void insert_node(int data, struct Node* head) {
	
	//exchange the data between a new node and head
	struct Node* newNode = SIZE_NODE;
	newNode->data = head->data;
	newNode->next = head->next;
	
	head->data = data;
	head->next = newNode;
}


void delete_node(int index, struct Node* head) {
	if (index < 0) return;
	
	struct Node* currentNode = head;
	
	int i;
	for(i = 0; i < index; i++) {
		if(currentNode->next) {
			currentNode = currentNode->next;
		} else {
			printf("\nERROR:\nSuch elem does not exist!");
			return;
		}
	}
	
	//If we reach here, then node with index i exists.
	//Consider 3 cases:
	
	if(currentNode == head) {
		//Case 1
		//If index == head node, delete the head
		if(head->next) {
			head->data = head->next->data;
			
			if(head->next->next) {
				head->next = head->next->next; 
			} else {
				head->next = NULL;
			}
			
			//printf("\n%d\n", head->data);
		} else {
			head->data = NULL;
		}
	} else if(!currentNode->next) {
		//Case 2
		//delete the last elem of the linked list
		struct Node* prevElemBeforeDeleted = head;
		
		for(i = 0; i < index - 1; i++) {
			prevElemBeforeDeleted = prevElemBeforeDeleted->next;
		}
		
		prevElemBeforeDeleted->next = NULL;
	} else {
		//Case 3
		//The node which is going to be deleted has prev. and next elements
		
		struct Node* prevElemBeforeDeleted = head;
		
		for(i = 0; i < index - 1; i++) {
			prevElemBeforeDeleted = prevElemBeforeDeleted->next;
		}
		
		struct Node* afterElemBeforeDeleted = currentNode->next;
		
		//Connected prev. and next elements
		prevElemBeforeDeleted->next = afterElemBeforeDeleted;
	}
	
}

int main(){
 	//HEADER of the linked list
	struct Node* head = SIZE_NODE;
 	head->data = 5;
 	
	//Additional elements
	struct Node* firstElem = SIZE_NODE;
	firstElem->data = 10;
	head->next = firstElem;
	firstElem->next = NULL;
	
	struct Node* secElem = SIZE_NODE;
	secElem->data = 15;
	firstElem->next = secElem;
	secElem->next = NULL;
	
	struct Node* thirdElem = SIZE_NODE;
	thirdElem->data = 17;
	secElem->next = thirdElem;
	thirdElem->next = NULL;
	
	struct Node* fourthElem = SIZE_NODE;
	fourthElem->data = 20;
	thirdElem->next = fourthElem;
	fourthElem->next = NULL;
	
	insert_node(100, head);
	insert_node(500, head);
 	
 	//printf("%d", head->next->next->next->next->data);
 	print_list(head);
 	printf("\n");
 	
 	delete_node(0, head);
 	delete_node(5, head);
 	delete_node(1, head);
 	
 	print_list(head);
 
	getchar();
	return 0;
}
