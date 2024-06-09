# Makefile to compile specified .c files into executables with the same name
# and to compile mylibrary.c into a shared library, along with key_check.c.

# Compiler to use
CC = gcc

# Rule to build all executables and the shared library
all: 0 3 4 mylibrary.so key_check

# Rule to build each executable
0: 0.c
	$(CC) -s 0.c -o 0

3: 3.c
	$(CC) -s 3.c -o 3

4: 4.c
	$(CC) -s 4.c -o 4

# Rule to build the shared library
mylibrary.so: mylibrary.c
	$(CC) -o mylibrary.so -shared mylibrary.c -ldl -fPIC

# Rule to build the key_check executable
key_check: key_check.c
	$(CC) -o key_check key_check.c

# Clean up generated files
clean:
	rm -f 0 3 4 mylibrary.so key_check
