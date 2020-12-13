#include <stdio.h>
#if 0
enum color {
	RED, BLUE, GREEN, WHITE
};
enum color function()
{
	return RED;
}

#endif

#if 0
// typedef example
unsigned short int var;
typedef unsigned short int u_int16;
u_int16 var2;

struct node {
	void* data;
	struct node* nect; // self referential structure
};

struct node* head; // head is pointer , points to struct node
struct node* tail;

typedef struct node* NODPTR; // form now onwards NODPTR is used instead of struct node*
NODPTR head1;
NODPTR tail1;
#endif

#if 0
// typedef with stucture
typedef struct {
	char name;
	int id;
}student;

student s1;
s1.name = "SANDEEP";
s1.id = 123;
printf("%d\n", s1.id);
#endif

#if 0
// structures
struct compound_datapacket {
	int id;
	char* name;
	char* data;
};

typedef struct compound_datapacket C_DATA;

C_DATA arr2[10]; // array of 10 compound data packets

C_DATA obj1; // one compound data packet, declared not intialized


C_DATA obj2 = { 10,"ABB", NULL }; //// one compound data packet, declared and intialized

//one compound data packet, declared and intialized seperately
obj1.id = 20;
obj1.name = "SANDEEP";
obj1.data = malloc(10);
strcpy(obj1.data, "DATA");

myStruct var;
sizeof(var); // 8 bytes


#endif

#if 0
// structure padding
#pragma pack(1) // to avid structure padding 

struct myStruct {
	char c1; // 1 byte
	char c2; // 1 byte
	char c3; // 1 byte
	char c4; // 1 byte
	char c5; // 1 byte
	int i;  // 4 byte
};

int main() {
	struct myStruct var1;
	printf("%d\n", sizeof(var1)); // 8 bytes are over it go to next 4 bytes so total 12 bytes (without pack(1)),with pack(1) it is 9

	while (1);
	return 0;
}
#endif

#if 0
// unions - memebers of the union shares memory
union myUnion {
	unsigned char c; // 1 byte
	unsigned int i;  // 4 byte
};
int main() {
	union myUnion var2;
	//printf("%d\n", sizeof(var2)); // 4 bytes / max (data members)
	var2.c = 0x4F;
	printf("%x\n", var2.c); // 0x4F
	var2.i = 0x7BCDEF55;

	printf("%x\n", var2.c); // 55 (expected to be 4F)
	printf("%x\n", var2.i); // 0x7BCDEF55

	while (1);
	return 0;
}
#endif

#if 0
#pragma pack(1)
union myUnion {
	unsigned char c; // 1 byte
	unsigned int i;  // 4 byte
};

union REG_A {
	struct {
		char RegBank;
		short int PSW;
		char Reserved;
	};
	int Full;
};

void dummy()
{
	union REG_A reg;
	reg.Full = 0x00ABCDEF;
	reg.RegBank = 0x77;
	reg.PSW = 0x6644;

	printf("%x\n", reg.Full);
}

int main() {

	dummy();

	while (1);
	return 0;
}
#endif

#if 0
// bit fields // bit level controllable memory in a register
struct bf {
	unsigned char b0 : 1;// 1 bit// 0 to 1
	unsigned char b1_b3 : 3; // 3 bits // 0x0 --0x07
	unsigned char b4_b7 : 4; // 4 bits // 0x0 -- 0xF

};

int main() {
	struct bf reg;
	reg.b0 = 0;
	reg.b1_b3 = 0x7;
	reg.b4_b7 = 0xF;

	printf("%d\n", sizeof(struct bf)); // 1 byte - 8 bits
	printf("regb0...%x\n", reg.b0);
	printf("regb1_3...%x\n", reg.b1_b3);
	printf("regb4_7...%x\n", reg.b4_b7);

	while (1);
	return 0;
}
#endif
