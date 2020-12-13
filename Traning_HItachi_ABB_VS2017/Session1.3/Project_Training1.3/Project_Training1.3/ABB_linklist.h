#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define _CRT_SECURE_NO_WARNINGS

// representation of a node inside a linklist
struct linklist_node {
	void* dataPtr;
	struct linklist_node* next;
};

typedef struct linklist_node NODE;
typedef struct linklist_node* NODEPTR;

// declaration
extern NODEPTR head;
extern NODEPTR tail;

extern void initList();
extern int addNode(void* data);
extern void displaylist();
extern void deletelist();
extern void reverseList();

extern int insertNode(void* data);

// Question 1
//insert the new node, after a existing node node matches 2nd argument otherwise insert it at the end
//InsertNode(void* data, void* prev_Node_Data);

//usecase:
// insertNode("PacketX", "packet_3 data_No");
// the new node gets inserted after node-3 ie in between node 3 and node 4

// insertNode("PacketX", "XYZ");
// the new node which is packetX will be added at the end

// Question 2
// updateNode("data to be updated", "already existing data");

//useCase:
//updateNode("packetX","packet3 ABB"); //Search node with this data, if data matches, it will update the data to the new data
//First free the already existing memory.
//Then allocate the new memory for packetX
//and finally copy the string. be careful

//Question 3
//reverseList() //head will point to the last node, tail will point to the first and all pointers will be reversed


