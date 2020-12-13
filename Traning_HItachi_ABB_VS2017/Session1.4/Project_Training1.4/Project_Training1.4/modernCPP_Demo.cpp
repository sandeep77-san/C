#include<iostream>
#include <string.h>

using namespace std;

#if 0
// why we use class insted of struct??

struct mySmartPtr {
	//Acess specifiers: Public, private, protected
	int i; // data member be default is public
};

class mySmartPtr {
	//Acess specifiers: Public, private, protected
	int i; // data member be default is public
};

int main{
	mySmartPtr_struct_obj;
    struct_obj.i = 100;// we can acess i outside the struct

  mySmartPtr_struct_obj;
  class_obj.i = 200;
}

#endif

#if 0
// class - collection of hetegenoius members - user defined type - size is summation of data members (similar to struct) 
class mySmartPtr {
private:
	// data members
	char* ptr;
	//int i = 0; in class - intialization is allowed from C++11 onwards

	//char c;
	//mySmartPtr(); //constructor- a special member function
	               //- it doesnt have any return type
	              // - the name of this function is same as that of class
	             // - it is invoked automatically once class is created

	//constructor supposed to do what??
	 // -it should intialize the object
	 // constuctors can be overloaded
public: 
	mySmartPtr() { //default ctor
		cout << "This is ctor " << endl;
		ptr = nullptr; //nullPtr is a c++11 feature--old code ptr = NULL;
	}
	// explicit mySmartPtr(const char* s); cant acts as conversion ctor
	mySmartPtr(const char* s) { //1 Arg ctor // it is called conversion ctor
		cout << "This is 1 arg ctor "<<endl;
		ptr = new char[strlen(s) + 1]; //dynamic memory allocation in C++
		strcpy(ptr, s);
		}
	~mySmartPtr() { // Dctor will be called if obj goes out of scope
		cout << "Dtor is called " << endl;
		if (ptr != nullptr) {
			delete[] ptr;
		}
		// Dctors cant be overloaded
	}
	// copy ctor
	mySmartPtr(const mySmartPtr& rhs) { // we dont want chnage the orginal object for const is used
		//this->ptr = rhs.ptr // shallow copy
		this->ptr = new char[strlen(rhs.ptr) + 1];
		strcpy(this->ptr, rhs.ptr); // deep copy
	}
	//getter
	char* getStr() const {
		return ptr;
	}
	// overloaded assignment operator =
	mySmartPtr& operator=(const mySmartPtr& rhs) {

		if (this != &rhs) //to check for self assignment
		{
			delete[] this->ptr; // free the memory of LHS object
			//this->ptr = rhs.ptr // shallow copy,we shouldnt do this
			this->ptr = new char[strlen(rhs.ptr) + 1];
			strcpy(this->ptr, rhs.ptr); // deep copy
		}
		return *this;
	}

};

int main() {

	mySmartPtr obj1;//object is an instance of a class // here default ctor is invoked

	mySmartPtr obj2("HITACHI_ABB"); // 1 arg ctor/ type of arg is const char*

	//mySmartPtr obj3 = "SAIF";// it will allow since type is char* for 1 single arg cotor//
	//mySmartPtr obj4 = 100.33"; // not allowed , since mySmartPtr ctor is char*
		
	mySmartPtr* p1 = new mySmartPtr;
	mySmartPtr* p2 = new mySmartPtr("SAIF");//memory allocated on heap
	///no of ctor called that many time dctor to be called
	delete(p1);// if we dont free p1, p2 which are point to heap memory leads to memory leak
	delete(p2);
	//now p1 an p2 dangling pointer 
	p1 = nullptr;
	p2 = nullptr;
	
	
	mySmartPtr obj3(obj2); // type of obj2 mySmartPtr, but it requries const char*
	                        // copy ctor is invoked
	
	// when Dctor called for obj3 it clear memory points to obj3 as well obj2 since both are pointing to same memory
	// whne Dctor called for onj2, it try to clear the memory already cleared above
	// will get run time error- soln - we should define copy constuctor

	mySmartPtr obj4 = obj2; //copy constructor is invoked // whenver new object created from exisiting object

	mySmartPtr obj5 = "SAIF";
	
	cout << obj2.getStr() << endl;
	cout << obj3.getStr() << endl;

	obj5 = obj2; // just asignment - again same run time error
	             // obj5.operator = (obj2)
	obj5 = obj2 = obj3; //obj5.operator = (obj5.operator = (obj3)) = (void)


	while (1);
	return 0;
}

#endif



#if 0
//ctor properties and use cases
class X {
	int i;
	int j;
};

class ij {
	int i;
	int j;
public:
	ij() { // default ctor
		i = 0;
		j = 0;
	}
};

// case 3 we cant created object with default ctor once user has given ctor
class ij2 {
	int i;
	int j;
public:
	ij2(int k) { // default ctor
		i = 0;
		j = 0;
	}
};

//case 4
class ij3 { 
	int i;
	int j;
public:
	ij3() = default; // keyword, it is specifier, tells compiler to synthesize default behavoiur
	
	ij3(int k) { // default ctor
		i = 0;
		j = 0;
	}
};

//case 5
class ij4 {
	int i;
	int j;
public:
	ij4() = delete; // tell complier not to synthesis default ctor
	ij4(int i1, int j1) {
		i = i1;
		j = j1;
	}
	//ij4(int i1, int j1):i(i1), j(j1) {}// using member intilizer list
};

//case 6
class ij5 {
	int i =0;
	int j =0;
public:
	ij5(int i, int j) {
		i = i; // self assignment
		j = j; // self assignment
	}
	
};

//case 7 application of 'this' pointer to avoid case 6 problem
class ij6 {
	int i = 0;
	int j = 0;
public:
	ij6(int i, int j) {
	//	i = i; // self assignment
	//j = j; // self assignment
		this->i = i; //this pointer automatically passed by compiler as the first argument to evry non static member function
		this->j = j;
	}

};

//compiler synthesizes following for us
// 1 -default ctor, if user has not written any ctor
// 2 - copy ctor, if user has not written copy ctor
// 3- operator =()
//4 - desctructor
// 5 - move ctor
// 6- move operator=() conditions appiled*
void func() {
	X obj1; // deafult ctor is invoked 
	X obj2(10); // Error
	
	ij obj1;
	ij obj2(10);// Error

	ij2 obj1;// no default ctor (point 1)
	ij2 obj2(10); // valid

	ij3 obj1;// Valid
	ij3 obj2(10); // valid

	ij4 obj1;// Error
	ij4 obj2(10);//valid

	ij5 obj1(10, 20); // i, j will remain at 0
	ij6 obj1(10, 20); // i=10, j =20;

}
#endif


