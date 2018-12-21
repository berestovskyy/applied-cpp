# Applied C++: Align Array Elements
How to align elements in an array using C++11 alignas specifier.

## Analysis
Please see the [detailed analysis on Medium](https://medium.com/applied/applied-c-align-array-elements-32af40a768ee).

## Compilation
	$ make
	c++ -Wall -std=c++17 -O3   -c -o align-array-elements.o align-array-elements.cpp
	c++ -o align-array-elements align-array-elements.o

## Example Run
	$ ./align-array-elements
	int array[4];
		checking element at address 0x1003e90d0: not aligned to 64 bytes
		checking element at address 0x1003e90d4: not aligned to 64 bytes
		checking element at address 0x1003e90d8: not aligned to 64 bytes
		checking element at address 0x1003e90dc: not aligned to 64 bytes
	alignas(64) int option_1[4];
		checking element at address 0x1003e9100: aligned to 64 bytes
		checking element at address 0x1003e9104: not aligned to 64 bytes
		checking element at address 0x1003e9108: not aligned to 64 bytes
		checking element at address 0x1003e910c: not aligned to 64 bytes
	int __attribute__((aligned(64))) option_2[4];
		checking element at address 0x1003e9140: aligned to 64 bytes
		checking element at address 0x1003e9144: not aligned to 64 bytes
		checking element at address 0x1003e9148: not aligned to 64 bytes
		checking element at address 0x1003e914c: not aligned to 64 bytes
	int option_3[4] __attribute__((aligned(64)));
		checking element at address 0x1003e9180: aligned to 64 bytes
		checking element at address 0x1003e9184: not aligned to 64 bytes
		checking element at address 0x1003e9188: not aligned to 64 bytes
		checking element at address 0x1003e918c: not aligned to 64 bytes
	typedef __attribute__((aligned(64))) int aligned_t;
	aligned_t option_4[4];
		checking element at address 0x1003e91c0: aligned to 64 bytes
		checking element at address 0x1003e91c4: not aligned to 64 bytes
		checking element at address 0x1003e91c8: not aligned to 64 bytes
		checking element at address 0x1003e91cc: not aligned to 64 bytes
	struct AlignedField { alignas(64) int field; };
	AlignedField solution_1[4];
		checking element at address 0x1003e9200: aligned to 64 bytes
		checking element at address 0x1003e9240: aligned to 64 bytes
		checking element at address 0x1003e9280: aligned to 64 bytes
		checking element at address 0x1003e92c0: aligned to 64 bytes
	struct alignas(64) AlignedStruct { int field; };
	AlignedStruct solution_2[4];
		checking element at address 0x1003e9300: aligned to 64 bytes
		checking element at address 0x1003e9340: aligned to 64 bytes
		checking element at address 0x1003e9380: aligned to 64 bytes
		checking element at address 0x1003e93c0: aligned to 64 bytes
	Alignment of 'max_align_t' is 16 bytes
	Alignment of 'int' is 4 bytes
