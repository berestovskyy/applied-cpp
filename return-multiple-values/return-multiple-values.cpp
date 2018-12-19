/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2018 Andriy Berestovskyy
 *
 * Applied C++: Return Multiple Values
 * The best way to return multiple values from a C++17 function
 */

#include <iostream>
#include <tuple>
#include <utility> /* for std::pair */

/*
 * "Do I Know This Already?" Quiz
 * What is the best way to return multiple values from a C++ function?
 */

/* Option 1: Using output parameters */
auto output_1(int &i1) {
  i1 = 11;    // Output first parameter
  return 12;  // Return second value
}

/* Option 2: Using a local structure */
auto struct_2() {
  struct _ {  // Declare a local structure with 2 integers
    int i1, i2;
  };
  return _{21, 22};  // Return the local structure
}

/* Option 3: Using an std::pair */
auto pair_2() { return std::make_pair(31, 32); }  // Just one line!

/* Option 4: Using an std::tuple */
auto tuple_2() { return std::make_tuple(41, 42); }  // Just one line!

// Use volatile pointers so compiler could not inline the function
auto (*volatile output_1_ptr)(int &i1) = output_1;
auto (*volatile struct_2_ptr)() = struct_2;
auto (*volatile pair_2_ptr)() = pair_2;
auto (*volatile tuple_2_ptr)() = tuple_2;

int main() {
  int o1, o2;             // Define local variables
  o2 = output_1_ptr(o1);  // Output 1st param and assign the 2nd
  // Use printf() so compiler could not optimize the variables out
  printf("output_1 o1 = %d, o2 = %d\n", o1, o2);

  auto [s1, s2] = struct_2_ptr();  // Structured binding declaration
  printf("struct_2 s1 = %d, s2 = %d\n", s1, s2);

  auto [p1, p2] = pair_2_ptr();  // Structured binding declaration
  printf("pair_2 p1 = %d, p2 = %d\n", p1, p2);

  auto [t1, t2] = tuple_2_ptr();  // Structured binding declaration
  printf("tuple_2 t1 = %d, t2 = %d\n", t1, t2);
}
