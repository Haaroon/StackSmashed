#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	char buffer[150];
	printf("%p\n", buffer);
	strcpy(buffer, argv[1]);
	printf("%s\n", buffer);
	return 0;
}