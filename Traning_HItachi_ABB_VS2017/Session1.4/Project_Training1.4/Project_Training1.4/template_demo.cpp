#include <iostream>
#include <stdio.h>

using namespace std;
// take code from sir

//Templated are used for generic programming
//

#if 0

template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t; // no separator after the last element in the pack
}



// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
	os << t << ", "; // print the first argument
	return print(os, rest...); // recursive call; print the other arguments
}



int main()
{
	int i = 10, j = 20, k = 30;
	double d = 30.34;
	print(cout, i, j, k, 50, d, "saif", "ABB", 43.45, 56.7890, 'c');
	cout << "\n";
}



// print(cout, i, j, k, 50, d);    -- os = {cout}, t = {i}, rest... = {j,k,50,d}
// print(cout, j, k, 50, d); -- -- os = {cout}, t = {j}, rest... = {k,50,d}
// print(cout, k, 50, d); -- -- os = {cout}, t = {k}, rest... = {50,d}
// print(cout, 50, d); -- -- os = {cout}, t = {50}, rest... = {d}
// print(cout, d); -- -- os = {cout}, t = {d}, rest... = {}

#endif