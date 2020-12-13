#pragma once
#include "ABB_linklist.h"
#include <stdio.h>
#if 1
int main()
{
	initList();	// function call
	addNode("packet_1 data"); // it should pass data of type char*
	addNode("packet_2 data_hello");
	addNode("packet_3 data_No");
	addNode("packet_4 data");
	addNode("packet_5 data");
	addNode("packet_6 data");

	//Question 1 
	//insertNode("packet_4 data");

	// Question 3
	reverseList();

	displaylist();
	//deletelist();


	while (1);
	return 0;
}
#endif


