#include <stdio.h>

int main()
{
	unsigned char ch1 = 0xAA; // 10101010
	unsigned char ch2 = 0x55; // 01010101

#if 0
	printf("Logical AND: %d\n", ch1&&ch2);
	printf("Bitwise AND: %d\n", ch1&ch2);
	
	// set bit number 4
	printf("%x\n", (ch1 | (1 << 4))); // 10111010 0xBA
#endif

	//set bit4 and bit6 ?
	unsigned char mask_1 = (1 << 4) | (1 << 6); //11111010 - FA
	printf("%x\n", ch1 | mask_1);
	
	// reset bit5
	unsigned char mask_2 = ~(1 << 5);
	printf("%x\n", ch1 & mask_2); // 10001010 - 8A

	// toggle bit5
	unsigned char mask_3 = (1 << 5);
	printf("%x\n", (ch1 ^ mask_3)); // 10001010 - 8A

	while (1);
	return 0;
}