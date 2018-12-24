##
## SPDX-License-Identifier: MIT
## Copyright (c) 2018 Andriy Berestovskyy <berestovskyy@gmail.com>
##

PROG     = $(basename $(word 1, $(wildcard *.cpp)))
CXXFLAGS+= -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith \
           -Wcast-qual -Werror -std=c++17 -O3
LDFLAGS +=

OBJS     = ${PROG}.o

${PROG}: ${OBJS}
	${CXX} -o ${PROG} ${OBJS} ${LDFLAGS}

clean:
	${RM} ${PROG} ${OBJS}
