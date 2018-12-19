# Applied C++: Return Multiple Values

## Analysis
Please see the [detailed analysis on Medium](https://medium.com/applied/applied-c-return-multiple-values-b142ff8c014a).

## Compilation
	$ make
	c++ -Wall -std=c++17 -O3   -c -o return-multiple-values.o return-multiple-values.cpp
	c++ -o return-multiple-values return-multiple-values.o

## Example Run
	$ ./return-multiple-values
	output_1 o1 = 11, o2 = 12
	struct_2 s1 = 21, s2 = 22
	pair_2 p1 = 31, p2 = 32
	tuple_2 t1 = 41, t2 = 42
