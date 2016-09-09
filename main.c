#include <stdio.h>
#include <string.h>
#include <unistd.h>

char name[9];

/* Wait for enter command before continuing */
int enterToContinue(){
	printf("> Press enter to continue\n>>");
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

/* clear the damn screen */
void clearScreen() {
  const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
}

/* Get name from user */
static int setName(){
	printf("> Please enter your name (Max 8 characters) \n> below followed by [Enter] key:\n>> ");
	fgets(name,10,stdin);
	// remove new line har
	name[ strlen(name) - 1 ] = '\0';
	printf("\n> Welcome %s to the game! \n", name);
	enterToContinue();
	clearScreen();
}

int loadSaveGame(){
	//TODO Load Save Game
}

int saveGame(){
	//TODO Save Game
}

/* starting message */
static int welcome(){
	printf("********************\n");
	printf("> Welcome to my text based game\n");
	//TODO Add a check for the savegame here
	setName();
	printf("> Please follow instructions carefully to progress\n");
	printf("> Lines starting with > are informational\n");
	printf("> Lines starting with >> expect your input\n");
	printf("> Enter h for the help menu\n");
	sleep(1);
	printf("> This game can only be played using a keyboard\n");
	printf("> Enter s to save\n");
	sleep(1);
	enterToContinue();
	printf("********************\n");
	return 0;
}

/* Main method, duhh */
int main() {
	welcome();
	printf("> %s, You wake up, all wet and flustered.\n", name);
	printf("> Its dark, it seems you have been injured but patched up.\n");
	//while(getInput() && parseCommand());
	printf("> Come again!\n");
	return 0;
}