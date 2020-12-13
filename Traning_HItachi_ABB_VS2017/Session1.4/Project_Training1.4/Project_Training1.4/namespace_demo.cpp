#if 0 // code c in c++
#include <stdio.h>
 
namespace lib_B {  // forward declaration
	extern int x;
}

namespace lib_A {
	int x = 10;
	void fun() {
		printf("lib_A.x= %d\n", x);
		printf("lib_B.x= %d\n", lib_B::x);
	}
}

namespace lib_B {
	int x = 20;
	void fun() {
		printf("lib_B.x= %d\n", x);
		printf("lib_A.x = %d\n", lib_A::x);
	}

}
int x = 30; //global variable
int main() {

#if 0
	int x = 40; // local variable
	printf("local_x= %d\n", x);
#endif

	//printf("global_x= %d\n", x);
	//printf("lib_A.x = %d\n", lib_A::x);
	//printf("lib_B.x= %d\n", lib_B::x);
	lib_A::fun();
	lib_B::fun(); 
	


	while (1);
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std; // forward declaration of std name space
int main() {

	//std::cout<< "Hello world\n"; // cout is variable defined in std name space and without forwrad declaration
	cout << "Hello world\n"; // with forward declaration

	while (1);
	return 0;
}
#endif