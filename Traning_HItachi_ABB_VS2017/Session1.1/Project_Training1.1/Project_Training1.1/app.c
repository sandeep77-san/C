#include <stdio.h>
#define ARG0

#include "MathLib.h"
#include "MathLib.c"

int main()
{
	#if 0
	  printf("ssff");
	  while (1);
	#endif

	#if 0
	  printf("%d \n", sum());
	  char ch1 = 127;
	  printf("%c \t %d \t %x\n", 'A', 'A', 'A');
	  printf("%c \t %d \t %x\n", 0x65, 0x65, 0x65);
	  printf("%d\n", ch1);
	  ch1++;
	  printf("%d \t %x\n", ch1, ch1);

	  unsigned char ch2 = 256;
	  printf("%d\n", ch2);

	  printf("%d\n", sizeof(int)); // by default int is long int
	#endif


	  while(1);
	return 0;
}

