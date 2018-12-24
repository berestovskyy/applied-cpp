# Applied C++: Align Array Elements

How to align elements in an array using C++11 alignas specifier.

## Analysis

Please see the [detailed analysis on Medium](https://medium.com/applied/applied-c-align-array-elements-32af40a768ee).

## Compilation

    $ make && ./align-array-elements
    c++ -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith -Wcast-qual -Werror -std=c++17 -O3   -c -o align-array-elements.o align-array-elements.cpp
    c++ -o align-array-elements align-array-elements.o

## Example Run

    int array[4];
        element at address 0x1076320d0 is not aligned to 64 bytes
        element at address 0x1076320d4 is not aligned to 64 bytes
        element at address 0x1076320d8 is not aligned to 64 bytes
        element at address 0x1076320dc is not aligned to 64 bytes
    alignas(64) int option_1[4];
        element at address 0x107632100 is aligned to 64 bytes
        element at address 0x107632104 is not aligned to 64 bytes
        element at address 0x107632108 is not aligned to 64 bytes
        element at address 0x10763210c is not aligned to 64 bytes
    int CACHE_ALIGNED option_2[4];
        element at address 0x107632140 is aligned to 64 bytes
        element at address 0x107632144 is not aligned to 64 bytes
        element at address 0x107632148 is not aligned to 64 bytes
        element at address 0x10763214c is not aligned to 64 bytes
    int option_3[4] CACHE_ALIGNED;
        element at address 0x107632180 is aligned to 64 bytes
        element at address 0x107632184 is not aligned to 64 bytes
        element at address 0x107632188 is not aligned to 64 bytes
        element at address 0x10763218c is not aligned to 64 bytes
    typedef CACHE_ALIGNED int aligned_t;
    aligned_t option_4[4];
        element at address 0x1076321c0 is aligned to 64 bytes
        element at address 0x1076321c4 is not aligned to 64 bytes
        element at address 0x1076321c8 is not aligned to 64 bytes
        element at address 0x1076321cc is not aligned to 64 bytes
    struct AlignedField { alignas(64) int field; };
    AlignedField solution_1[4];
        element at address 0x107632200 is aligned to 64 bytes
        element at address 0x107632240 is aligned to 64 bytes
        element at address 0x107632280 is aligned to 64 bytes
        element at address 0x1076322c0 is aligned to 64 bytes
    struct alignas(64) AlignedStruct { int field; };
    AlignedStruct solution_2[4];
        element at address 0x107632300 is aligned to 64 bytes
        element at address 0x107632340 is aligned to 64 bytes
        element at address 0x107632380 is aligned to 64 bytes
        element at address 0x1076323c0 is aligned to 64 bytes
    Alignment of 'max_align_t' is 16 bytes
    Alignment of 'int' is 4 bytes
