#include<iostream>
#include <string.h>

using namespace std;

//RAII - Resource allocation is intialization

#if 0
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
		cout << "This is 1 arg ctor " << endl;
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

	//move semantic or move ctor
	mySmartPtr(mySmartPtr&& temp) {//r value reference as argument
		cout << "This is move ctor" << endl;

		this->ptr = temp.ptr;
		temp.ptr = nullptr;

	}
	// move operator =
	mySmartPtr& operator=(const mySmartPtr&& rhs) {
		cout << "This is move operator=" << endl;
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

// Factory method 
mySmartPtr getObjectFromFactory(const char* s) {
	mySmartPtr obj(s);
	return obj;

}


int main() {

	mySmartPtr obj1 = getObjectFromFactory("ABCDEF");
	mySmartPtr obj2("hello");
	
	obj2 = std::move(obj1);

	while (1);
	return 0;
}

#endif