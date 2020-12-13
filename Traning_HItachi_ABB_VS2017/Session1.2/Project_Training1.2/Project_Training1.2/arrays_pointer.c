#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
#if 1
	//difference between scanf and sscanf 

	char s1[3], s2[3] = "San";
	printf("Enter string: ");
	scanf("%s", &s1);
	printf("s1: %s\n", s1);
	printf("s1 address %d\n", &s1);
	sscanf(s1,"%s",s2); // s1 will get copied to s2
	printf("s2: %s\n", s2);
	printf("s1 address %d\n", &s1);
	printf("s2 address %d\n", &s2);


#endif

#if 1
	//difference between printf and fprintf
	//fprintf it used to perform write operation in the file pointed to by FILE handle
	//fprintf(filename, "control string ", argument);


#endif



#if 0
	int arr_1[] = {1,3,4,5,6}; // integer array
	char arr_c[3] = { 'A', 'B', 'C' };// 3 bytes //chracter array
	char arr_2[] = "hello"; // 6 bytes -one null charcter \0 
	char arr_3[] = { 'A', 'B', 'C', '\0' }; // 6 bytes -one null charcter \0 
	printf("%s\n", arr_c);
	printf("%s\n", arr_2);
	printf("%s\n", arr_3);
#endif
#if 0
	int b = 100;
	int* ptr; //unintialzed pointer -garbage value - 'Wild pointer'
	ptr = &b; // referencing a pointer // intialization of pointer
	printf("%d\n", *ptr); // de-referencing

	//int* ptr2 = NULL; // null pointers
	//printf("%d\n", *ptr2); // de-referencing
#endif

#if 0
	char c = 'x';
	char* ptr3 = &c; // size of char* int* folat* is the same 32bit/64bit
	printf("%c\n", *ptr3);

	// upcasting 
	int b = 100;
	char* ptr4 = &b; // No problem because it will fetch 1-byte(LSB) from given 4 bytes
	printf("%d\n", *ptr4);

	// downcasting
	int *ptr5 = &c;
	printf("%d\n", *ptr5); // gives garbage value (compiler gives segmentation fault)
#endif

#if 0
	char c = 'x';
	void* ptr = &c; // generic pointer (it can holds adress of any data type address)
	//printf("%c\n", *ptr); // error (compiler dont know how many bytes it needs to fetch)
	printf("%c\n", *(char*)ptr); // must to type cast
#endif

#if 0
	char* ptr = (char*)malloc(4); // dynamical allocates memory on heap section// ptr is on stack , ptr holds heap address
	free(ptr); // if dont free at the end of main ptr will get destoyed and dynamically memory will be get leaked

	//after free ptr is called as dangling pointer
	//*ptr = 100; // undefined behaviour
	//immediately after making pointer free, we need to assign to NULL as per roll books
	*ptr = NULL;
#endif

#if 0
	int arr[] = {1,2,3,4,5};
	int i = 10;
	int j = 20;
	int* ptr1 = &i;//pointer pointing to i
	int* ptr2 = arr;

	*ptr1 = 100;// i = 100 
	(*ptr1)++; // i = 101
	ptr1++; // becarefull where are we advancing pointer

	*ptr1 = &j; //pointer pointing to j
	*ptr1 = 200; // j =200

	*ptr2 = 10; // first element of array , arr[0]
	*ptr2++; // pointer pointing to next element
	*ptr2 = 20; //arr[1] = 20

	int k = *ptr2; // k = 20
	k = *ptr2++; /// k = 20 // ptr2 is dereferenced first the ptr2 increments, ptr2 = arr[2]
	k = *ptr2; ///k = 3; arr[2]

	k = ++*ptr2; //k = 4; ptr2 = arr[3]
	k = ++(*ptr2) // k = 5 ;ptr2 =  arr[3]
#endif

#if 0
	//const int ci; // rule: always intialize the constant at the time of declaration, we cannot modify it later since it is read only memory
	//ci = 10;
	const int ci = 10; // this is correct way

	int i = 10;
	int j = 20;
	int* ptr = &i;
	*ptr = 100;
	ptr = &j;

	const int* ptr1; // ptr1 is pointer to an read only integer constant location
	ptr1 = &i;
	*ptr1 = 100; // ERROR- we cant modify value 
	ptr1 = &j; //valid - can change adress of the value 


	int const* ptr2; //ptr2 is pointer to an read only integer constant location
	*ptr2 = 100;// Error
	ptr2 = &i; // valid

	int *const ptr3; // ptr3 is constant pointer points to integer 
	*ptr3 = 100; ///valid
	ptr3 = &i; //not valid

	int const *const ptr4 = &i; //ptr4 is constant pointer pointing to constant integer
	*ptr4 = 100// ERROR
	ptr4 = &j; // ERROR

#endif


	while (1);
	return 0;
}

