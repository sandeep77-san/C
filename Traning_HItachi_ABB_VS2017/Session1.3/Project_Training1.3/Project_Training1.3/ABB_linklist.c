#include "ABB_linklist.h"

// definition of global variables
NODEPTR head;
NODEPTR tail;
NODEPTR p;

//Definiton
void initList() {
	head = NULL;
	tail = NULL;
	p = NULL;
}

int addNode(void* data) {

#if 0
	NODE node1;		// local variable / auto variable - stored on stack

	char* d = (char*)data;

	// node1.dataPtr = malloc(sizeof(d)); //Logical ERROR
	node1.dataPtr = malloc(strlen(d) + 1);
	strcpy(node1.dataPtr, d);

	node1.next = NULL;

	head = &node1;
	tail = &node1;
#endif
	NODEPTR temp = (NODEPTR)malloc(sizeof(NODE) * 1); // node is created on heap
	NODEPTR p = NULL;
	char* d = (char*)data;
	temp->dataPtr = malloc(strlen(d) + 1);
	strcpy(temp->dataPtr, d);
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		//head->next = temp;// BUG
		tail->next = temp; // tail pointing to next 
		tail = temp;

#if 0 // my code 
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
		tail = p->next;
#endif

	}

	return 0;
}

void displaylist() {
	NODEPTR temp = head;
	while (temp != NULL)
	{
		printf("%s\n", (char*)temp->dataPtr);
		temp = temp->next;

	}
}

void deletelist() {
	NODEPTR temp = head;
	while (temp != NULL)
	{
		head = temp->next;
		printf("Deleting....%s\n", temp->dataPtr);
		free(temp->dataPtr);
		free(temp);
		temp = head;

	}
	tail = NULL;

}

int insertNode(void* data) {

	NODEPTR temp = (NODEPTR)malloc(sizeof(NODE) * 1); // node is created on heap
	NODEPTR p = NULL;
	NODEPTR match = NULL;
	char* d = (char*)data;
	temp->dataPtr = malloc(strlen(d) + 1);
	strcpy(temp->dataPtr, d);
	temp->next = NULL;

	
#if 0
	// insert at the begining
	temp->next = head;
	head = temp;
#endif

#if 0
	// insert at the end
	tail->next = temp;
	tail = temp;
#endif

#if 0
	// insert at node if input string macthes the node otherwise add at the end
	p = head;
	while (strcmp( p->dataPtr, temp->dataPtr)) { // if strings dont match strcmp is  high
		p = p->next;
		if (p == NULL)
		{
			tail->next = temp;
			tail = temp;
			break;
		}
	}
	if (p != NULL)
	{
		temp->next = p->next;
		p->next = temp;
	}
	
#endif
	return 0;
}

void reverseList() {

	NODEPTR temp = NULL;



}



