#include<iostream>
#include <memory.h>// for smart pointers
using namespace std;

//---------- smart pointers-------//
// - autoptr
// - uniqueptr
// - shareptr
// -weakptr

#if 0
class Integer {
	int *p = nullptr;

public:
	Integer() {
		cout << "Integer()" << endl;
		p = new int;
	}
	~Integer() {
		cout << "~Inteegr()" << endl;
		delete p;
	}
	void display() {

	}
};

#endif
#if 0

int main() {

	//int* p = new int; // native pointer
	//*p = 100;
	//meory leak not freeing memory

	//stop using native pointer as c++11 use unique/share pointer
	
	unique_ptr<int> p = make_unique<int>();
	*p = 10;
	//now no need to freeing memory

	//Integer* q = new Integer();

	shared_ptr<Integer> r = make_shared<Integer>();

	r->display();

	while (1);
	return 0;

}
#endif

#if 0
int main() {
	int* p1 = new int;
	int* p2;
	p2 = p1;
	delete p2; // p1 become dangling pointer

	//*p1 = 100;// excpetion error

	//insted of above use share pointer
	shared_ptr<int> p3 = make_shared<int>();
	cout << "ref count -1=" << p3.use_count() << endl;
	shared_ptr<int> p4;
	p4 = p3;
	cout << "ref count -2=" << p3.use_count() << endl;
	
	*p3 = 100;
	cout << "ref count -3=" << p3.use_count() << endl;

	while (1);
	return 0;

}

#endif

#if 0
int main() {
	//Integer* q = new Integer();
	shared_ptr<Integer> p1 = make_shared<Integer>();
	cout << "ref count -1=" << p1.use_count() << endl;
	{
		shared_ptr<Integer> p2;
		p2 = p1;
		cout << "ref count -2=" << p1.use_count() << endl;
	}

	cout << "ref count -3=" << p1.use_count() << endl;

	while (1);
	return 0;

}

#endif

#if 0
int main() {
	//Integer* q = new Integer();
	shared_ptr<Integer> p1 = make_unique<Integer>();
	cout << "ref count -1=" << p1.use_count() << endl;
	{
		shared_ptr<Integer> p2;
		p2 = p1;
		cout << "ref count -2=" << p1.use_count() << endl;
	}

	cout << "ref count -3=" << p1.use_count() << endl;

	while (1);
	return 0;

}

#endif
