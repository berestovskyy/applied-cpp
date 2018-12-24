/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2018 Andriy Berestovskyy <berestovskyy@gmail.com>
 *
 * Applied C++: Align Array Elements
 * How to align element in an array using C++11 alignas specifier
 */

#include <iostream>

/*
 * Definition of CACHE_ALIGNED macro:
 *   for clang and GCC: attribute((aligned))
 *   for MSVC: declspec(align)
 *
 * Note: cache line size is 64 bytes for x86, but 128 bytes for ARM
 */
#if defined(__GNUC__)
#define CACHE_ALIGNED __attribute__((aligned(64)))
#elif defined(_MSC_VER)
#define CACHE_ALIGNED __declspec(align(64))
#endif

/*
 * The following variable is needed here to introduce a misalignment
 * for the following `array` variable.
 *
 * Without this global integer, the `array` will be the first global
 * variable in `.bss`, hence the first element of the `array` will be
 * aligned to the 64 bytes
 */
int _;

/*
 * "Do I Know This Already?" Quiz
 * How to define an array so each its element is aligned to 64 bytes?
 */
int array[4];

/* Option 1: Using alignas() at the very beginning of the definition */
alignas(64) int option_1[4];

/* Option 2: Using attribute((aligned)) after the type declaration */
int CACHE_ALIGNED option_2[4];

/*
 * Option 3: Using attribute((aligned)) at the very end
 * Note: this generates the following error on MSVC:
 *       error C2144: syntax error: 'int' should be preceded by ';'
 */
#if defined(__GNUC__)
int option_3[4] CACHE_ALIGNED;
#elif defined(_MSC_VER)
/* No option 3 for MSVC */
int option_3[4];
#endif

/*
 * Option 4: Using attribute((aligned)) and a typedef
 * Note: this generates the following error on GCC:
 *       error: alignment of array elements is greater than element
 */
#if defined(__clang__) || defined(_MSC_VER)
typedef CACHE_ALIGNED int aligned_t;
aligned_t option_4[4];
#else
/* No option 3 for GCC */
typedef int aligned_t;
aligned_t option_4[4];
#endif

/*
 * Solution (workaround): an array of structures
 */
struct AlignedField {
  alignas(64) int field;
};
AlignedField solution_1[4];

struct alignas(64) AlignedStruct {
  int field;
};
AlignedStruct solution_2[4];

using std::cout;

void check_alignment(const int &element) {
  /* Re-intepret address of the element as an unsigned integer */
  auto address = reinterpret_cast<std::uintptr_t>(&element);
  cout << "\telement at address " << &element << " is "
       << (address % 64 == 0 ? "aligned" : "not aligned") << " to 64 bytes\n";
}

int main() {
  cout << "int array[4];\n";
  for (auto &e : array) check_alignment(e);

  cout << "alignas(64) int option_1[4];\n";
  for (auto &e : option_1) check_alignment(e);

  cout << "int CACHE_ALIGNED option_2[4];\n";
  for (auto &e : option_2) check_alignment(e);

  cout << "int option_3[4] CACHE_ALIGNED;\n";
  for (auto &e : option_3) check_alignment(e);

  cout << "typedef CACHE_ALIGNED int aligned_t;\n"
          "aligned_t option_4[4];\n";
  for (auto &e : option_4) check_alignment(e);

  cout << "struct AlignedField { alignas(64) int field; };\n"
          "AlignedField solution_1[4];\n";
  for (auto &e : solution_1) check_alignment(e.field);

  cout << "struct alignas(64) AlignedStruct { int field; };\n"
          "AlignedStruct solution_2[4];\n";
  for (auto &e : solution_2) check_alignment(e.field);

  /* The output on my system is 16 (long double) */
  printf("Alignment of 'max_align_t' is %zd bytes\n", alignof(max_align_t));
  /* The output on my system is 4 */
  printf("Alignment of 'int' is %zd bytes\n", alignof(int));
}
