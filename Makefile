CC=gcc -m32
CFLAGS=-fno-stack-protector -z execstack

main: main.c 
	$(CC) $(CFLAGS) -o main main.c 