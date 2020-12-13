

#include <iostream>
using namespace std;

// exceptions(only in c++) load CPU 
// exception can hapen 
// -devide 0
// - memory access voilation
// - not able to connect to data base

#if 0
int main() {

	int* p = new int;
	throw 10;// we are creating an exception
	        // program abruptly terminated

	delete p;// releasing memory //(memory leak, system cant excute this )


}

#endif

// we can enclose body of code which you suspect it can give exception error in try block and write remedy for it in catch 
#if 0
int main() {

	int* p = nullptr;
	try {
		//-----//
		p = new int;
		throw 10;
	}
	catch (int i)
	{
		cout << "An expection ocured: " << i << endl;
		delete p;
		throw i;
	}

	while (1);
	return 0;

}

void fun() noexcept { // it is not suppose to throws exception

}
#endif



