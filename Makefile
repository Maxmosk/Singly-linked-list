.PHONY: all clean


#C programming language compiler
CC=gcc
#Compiler flags
CFLAGS=  -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align 
CFLAGS+= -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return 
CFLAGS+= -Wcast-qual -Wswitch-default -Wswitch-enum -Wunreachable-code 
CFLAGS+= -Wformat=2 -Werror -Winit-self -Wuninitialized -Wpointer-arith -save-temps 
CFLAGS+= -Wold-style-definition -Wstrict-prototypes -Wmissing-prototypes 
CFLAGS+= -Werror-implicit-function-declaration -Wlogical-op -Wduplicated-cond
CFLAGS+= -Wcast-qual -Wcast-align -Wformat-security 
CFLAGS+= -lasan -fsanitize=address,leak,undefined -fstack-protector 
CFLAGS+= -s -masm=intel -pedantic -std=c99


all: sorter


sorter: main.o singly_linked_list.o print_elem.o compare_elem.o
	$(CC) $(CFLAGS) -o sorter main.o singly_linked_list.o print_elem.o compare_elem.o

main.o: main.c
	$(CC) -c $(CFLAGS) -o main.o main.c
singly_linked_list.o: singly_linked_list.c
	$(CC) -c $(CFLAGS) -o singly_linked_list.o singly_linked_list.c
print_elem.o: print_elem.c
	$(CC) -c $(CFLAGS) -o print_elem.o print_elem.c
compare_elem.o: compare_elem.c
	$(CC) -c $(CFLAGS) -o compare_elem.o compare_elem.c

clean:
	rm -rf *.o sorter *.s *.i

