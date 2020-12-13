#include <iostream>
#include <memory.h>// for smart pointers
#include <vector>
using namespace std;

// concept 1 - structure declaraion in  C and C++
#if 0
struct myStruct {
	int x;
	// in c we cant define function inside the structure
	void fun() { // but in c++ we can declare, this function is member function
	}

};

// C program
struct myStruct Var;
Var.x = 100;

//in C++ program
myStruct Var;
Var = 200;
// size of empty struct in C is 0 bytes
// size of empty struct in C++ is 1 byte

#endif
/*------------------------*/
// concept 2 - function overloading

#if 0

//in C two function with same is not possible
// in C++ is possible with following conditions
 // -- the function should differ in :
//     -> number arg, type arg, order arg
//     -> the return type does play any role in function overloading

void function_A() { // zero arguments -allowed 

}
void function_A(int x) { //1 argument, type int -allowed 

}
void function_A(int* x) { //1 argument, type int* -allowed 

}
void function(int x, int y) // 2 argument -allowed 
{

}
void function(int* x, int y) // 2 argument -allowed 
{

}
void function(int x, int* y) // 2 argument -allowed // order is different
{

}
int function(int x, int* y) // 2 argument -not allowed 
{

}
#endif

/*------------------------*/
#if 0
// concept 3 - references // int& is only in C++
void fun()
{
	int x = 10; // x is int, declared , defined and intialized
	int* p; // p is pointer to int , p is declared, defined but not intialized
	p = &x; // initialized 
	*p = 200; //x = 200
	cout << "adrees of p" << &p << endl;
	int k = 1;
	p = &k;
	cout << "adrees of p" << &p << endl;

	int y = 20;
	int& ref = y; // it is a reference : a reference is an alias to a variable
	//( it must be intialized at the time declaration)
	// references shares adress of there variable
	ref = 300; // y = 300 // we are not making ref now to point to k , instead it just value assignement

}

#endif

//-------------------------//
// call by and value and call by adrees and call by reference in C++
#if 0

void myswap(int x, int y) // pass/call by value
{
	int temp = x;
	x = y;
	y = temp;
}

void myswap(int*x, int*y) // pass/call by adreess
{
	int temp = *x;
	*x = *y;
	*y = temp;

}

void myswap2(int&x, int&y) // pass/call by reference // int&x = a, int&y = b
{
	int temp = x;
	x = y;
	y = temp;

}

int main()
{
	int a = 10, b = 20;
	cout << "before the call" << endl;
	cout << "a = "<< a << endl;
	cout << "b = " << b << endl;

	//myswap(a, b); //call by value // copy of a, b made to x,y but atual a&b not chnaged
	//myswap(&a, &b); //call by adress // adress of of a, b made to adress of x,y so actual paramter can be chnages in myswap
	                  // with call by adress same memory shared by a,b with x and y..no etxra memory created for x&y
	myswap2(a, b); //call by reference // same advantage as call by address// internally the references are const pointer

	cout << "after the call " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	 

	while (1);
	return 0;
}
#endif

/*--------------*/
//concept 4 - inlin functions
//explained in inlinefunction_demo.cpp

/*---------------*/
//Concept5 - deafault arguments
#if 0
/*-------------*/
# if 0
int SUM_INT(int a)
{
	return (a);
}

int SUM_INT(int a, int b)
{
	return (a + b);
}

int SUM_INT(int a, int b, int c)
{
	return (a + b + c);
}
#endif

int SUM_INT(int a, int b=0, int c=0) // deafult arguments (one function serves all the purpose of above function
{
	return (a + b + c);
}

//int SUM_INT(int a =0, int b = 0, int c); // Wrong defintion
//int SUM_INT(int a, int b, int c =0, int d = 0); // Wrong, the default value is missing
int main() {

	SUM_INT(10); //10
	SUM_INT(10,20); // 30
	SUM_INT(10,20,30);// 60


	while (1);
	return 0;

}
#endif

#if 0
/// Question
#define SIZE 5
void sumelement(int& a) { // use pass by reference
	int i,b=a, sum =0;
	for (i = SIZE-1; i >=0; i--)
	{
		sum = sum + (b--);
	}
	a = sum;
	cout << a << endl;
	//int b = --a;
	//cout << b << endl;
}

int main()
{
	int arr[SIZE] = { 1,2,3,4,5};
	int a = arr[SIZE-1];
	sumelement(a);
	arr[SIZE - 1] = a;
	cout << arr[SIZE - 1] << endl; // should hold sum of all values
	while (1);
	return 0;
}

void sumelement(int(&arr)[5])
{

}
#endif

#if 0

//concept 6 - explicict, ctor, conversion ctor, desctuvtor, this pointer
//explained in moderCPP_Demo.cpp

// concept7  auto , decltypetype, constexpr, rangebased

int i = 10;
double d = 10.23;
double* Ptr = &d;
int* iPtr = &i;

// auto deduction of type
auto i1 = 10; // type of i gets from initializer(10)
//auto i2;// ERROR
auto d1 = 10.258;

auto iPtr = &i1; // int*
auto dPtr1 = &d1;// double*
auto iPtr2 = iPtr; // iPtr2 is int*

int const k = 10;
auto k1 = k; // k1 is not constant int it is just int -- sideeffect 1
             // auto rejects top-level const, 

int const* kPtr = &k1; //kPtr is pointer to a constant integer
int* const kPtr2 = &k1;
auto kPtr1 = kPtr; // kPtr1 is int const* //kPtr1 is not top level constant
auto kPtr3 = kPtr2; // kPtr3 is int* //kPtr3 is top level constant

int& ref1 = i1; // ref1 is int& // ref internally implemented as const pointer
auto ref2 = ref1; // ref2 is only int  --side effect 2

//overcome side effects of auto -decltype

decltype(k) k2 = 20; // type of k2 is const int unlike auto
decltype(ref1) ref3; // ref3 is int& unlike auto

//----- constexpr------------------
int init(const int i) {
	//----logic to return value//
	return (i*i);
}
constexpr int init1(const int i) {
	//----logic to return value//
	return (i*i);
}

void dummy() {
	const int i = init(7); // idealy we would like to get this evaluated at compile time
	// is it guaranteed?? No it is not 

	const int i1 = init1(7); // it is guaranteed to be evaluated at compile time with constexpr which improves performance at runtime
}



// range based using 
#include <vector>

void function_demo() {
	vector<double> vec = { 12.34, 45.65 };// vector is dynamic array and it can grow							
	//cppreference.com//
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	
	//range based for loop in C++11 //it supports only container supports array operator
	for (double e : vec) {
		cout << vec[i] << "\t";
	}

	for (auto e : vec) {
		cout << vec[i] << "\t";
	}

	vector<double>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << "\t";
	for (vector<double>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << "\t";
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << "\t";

#endif

#if 0
//concept8 - rvalue, rvalue reference
void rvalue_demo(){
	int y = 20; // y is l value and 20 is rvalue
	int x = 10;
	x = y;
	//any const which can come on RHS is rvalue.. any temporary is an rvalue

	int& ref1 = y; //ref is a l value reference can refer only to a lvalue
	//int& ref2 = 10; //ref2 is l value reference, assigned with rvalue//ERROR
	//const int& ref3 = 10; //it is a hack

	//in c++11 r-value reference

	int&& r_ref1 = 10; // r_ref1 is r value reference 


}

#endif
// concept 9 smart ppointer
// explained in smartPointer_demo.cpp

#if 0
//concept 10 - Lamdas

/* STL - standard template library*/
// - containers
// - sequentail containers
// - arrays, vector, list, dqueue
// - Associate containers
// - Algorithms

void fun_print(int i)
{
	cout << i << endl;

}

class Integer {
	int i;

};

void dummy_fun() {
	int i = 10;
	int arr[5] = { 1,2,3,4,5 };
	int* p = &i;
	int* pArr = arr;
	Integer* pObj = new Integer;

	void(*fPtr)(int); // fPtr is a pointer to function which takes one int arg and returns void

	fPtr = fun_print; // function name represents the function address

	void ForEach(const vector<int> &value, void(*fPtr)(int)) {
		for(auto )
	}



}
#endif
#if 0
//uisng c in c++
// name mangling / Name decoration
void fun1(int)
{

}
void fun1(int, int) {

}// function names mangled in c++ inetrnally name will be fun1_1, fun2_2 based on argumnets difference

extern "C" {

	auto y = 19;

	void fun3(int) {
	}
	void fun3(int, int) { // error in C but not in C++

	}
}
#endif

#if 0

//global varible
// static global variable -
int g_var = 10; // we can use g_var in another file making it as extern int g_var
static int g_var = 100; // we cant use g_var in another file even if you use extern // it throws linker error

#endif

// concept 11 - exception handling

// concept 12 - template