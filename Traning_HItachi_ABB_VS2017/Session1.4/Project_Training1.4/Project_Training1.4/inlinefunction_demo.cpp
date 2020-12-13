#include <iostream>
using namespace std;

//concept 4 : inline functions 
#if 0
#define FUN(a) a+1 // macro are substiuted at pre processing time , not called (no stacks creation)

int fun1(int a) {
	return (a + 1);
}
// inline is a request to the compiler to make inline
// like macros inline functions are not called, they are substituted during compile time
// inline is request to compiler not gauranteed ,
//the compiler can reject inline
// - if function is recursive
//   - if the function is big (>80 LOC - compiler specific)
//  - function defination and function call are in different files/translation unit
//  - if function uses any static variables


inline int fun2(int a) {
	return(a + 1);
}

int main() {
	cout << FUN(10) << endl; // no function is called
	cout << fun1(10) << endl; //for one line of function fun, a stack will be cretae and destoryed it affect performance 
	cout << fun2(10) << endl; // no stacks is cretaed

	while (1);
	return 0;
}


#endif
