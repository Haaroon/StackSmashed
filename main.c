#include <stdio.h>
#include <string.h>

int name=0;

/* Get name from user */
int setName(){
	char name[9];
	printf("Please enter your name (Max 8 characters) \nbelow followed by [Enter] key:\n");
	fgets(name,10,stdin);
	// remove new line har
	name[ strlen(name) - 1 ] = '\0';
	printf("\nWelcome %s to the game! \n", name);
}

int loadSaveGame(){
	//TODO Load Save Game
}

int saveGame(){
	//TODO Save Game
}

/* starting message */
int welcome(){
	printf("********************\n");
	printf("Welcome to my text based game\n");
	//TODO Add a check for the savegame here
	setName();
	printf("**Please follow instructions carefully to progress\n");
	printf("**Please type the letter h for the help menu\n");
	printf("**This game can only be played using a keyboard\n");
	printf("**At any time you may save by typing s then enter\n");
	printf("********************\n");
	return 0;
}


int main() {

	welcome();

}