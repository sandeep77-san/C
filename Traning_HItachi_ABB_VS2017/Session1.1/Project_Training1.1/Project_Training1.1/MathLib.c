#include "MAthLib.h"

// definitions

#ifdef ARG0
	int sum(void)
	{
		return 0;
	}
#endif

#ifdef ARG1
	int sum(int a)
	{
		return a;
	}
#endif

#ifdef ARG2
	int sum(int a, int b)
	{
		return (a+b);
	}
#endif