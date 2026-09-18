CFLAGS = -MMD -march=armv7-a -marm -mfpu=neon -g0 -O2 -DNDEBUG -save-temps 
LDFLAGS = -g0 -O2
LOADLIBES = -lm -lc

.PHONY: all test clean realclean

all: add_vector_tb test

add_vector_tb: add_vector_tb.o add_vector.o add_vector_ref.o add_vector_fast.o

test:
	./add_vector_tb

clean:
	-rm *.d *.o *.i *.s

realclean: clean
	-rm add_vector_tb

-include $(wildcard *.d)
