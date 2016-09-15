#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#pragma check_stack(off)

static char input[9];
static char name[150] = "HARAMBEEE";


/* Wait for enter command before continuing */
int enterToContinue(){
	printf("> Press enter to continue\n>>");
	fflush(stdout);
	int enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

/* clear the damn screen */
void clearScreen() {
	const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
	fflush(stdout);
}

void helpMenu(){
	printf(">*********************************\n");
	printf("> HELP MENU\n");
	printf("> Enter H for the help menu\n");
	printf("> Enter I to view your ID\n");
	printf("> This game can only be played using a keyboard\n");
	printf("> Lines starting with > are informational\n");
	fflush(stdout);
	sleep(0);
	printf("> Lines starting with >> expect your input\n");
	printf("> END HELP\n");	
	printf(">*********************************\n");
	fflush(stdout);
	sleep(0);
}

/* Get name from user */
void setName(){
	printf("> Please enter your name (Max 8 characters) \n> below followed by [Enter] key:\n>> ");
	fflush(stdout);
	gets(name);
	fflush(stdout);
	//gname = *name;
	// remove new line har
	//state1.name[ strlen(state1.name) - 1 ] = '\0';
	printf("\n> Welcome %s to the game! \n", name);
	fflush(stdout);
	enterToContinue();
	clearScreen();
}

/* starting message */
void welcome(){
	clearScreen();
	printf("********************\n");
	printf("> Welcome to my text based game\n");
	fflush(stdout);
	sleep(1);
	setName();
	printf(" Please follow instructions carefully to progress\n");
	fflush(stdout);
	sleep(2);
	helpMenu();
	enterToContinue();
	fflush(stdout);
	clearScreen();
	printf("********************\n");
}

int getInput()
{
	printf(">> ");
	fflush(stdout);
	scanf("%s", input);
	fflush(stdout);
  	return 1;
}

void showID(char* input){
 	//printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
	//fflush(stdout);
	printf(">*****************************\n");
	printf("> ID CARD\n");
	fflush(stdout);
 	char names[150];
    strcpy(names, input);
    printf("Name: %s\n", names);
 	//printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
	printf("> END ID CARD\n");
	printf(">*****************************\n");		
	fflush(stdout);
	
}

int checkStandardCommands(char* input){
	if(*input == 'H')
	{
		helpMenu();
		return 1;
	}
	else if (*input == 'I')
	{
		showID(name);
		return 1;
	}
	return 0;
}

void mainGame(){
	printf("> You see a two doors, which do you choose?\n");
	printf("> Type L for Left Door, Type R for Right door\n");
	fflush(stdout);
	int responded = 0; 
	while(!responded){
		getInput();
		fflush(stdout);
		if(*input == 'L')
		{
			clearScreen();
			printf("> You take the left door\n");
			break;
		}
		else if(*input ==  'R')
		{
			clearScreen();
			printf("> You take the right door\n");
			break;
		}
		else if (checkStandardCommands(input) == 0) {
			printf("> I do not understand, Try again\n");
		}
		fflush(stdout);
	}
	fflush(stdout);
	sleep(1);
	printf("> A man approches with a knife in hand. What do you do?\n");
	printf("> Type A to attack, Type T to talk.\n");
	fflush(stdout);

	while(!responded){
		getInput();
		fflush(stdout);
		if(*input == 'A')
		{
			clearScreen();
			printf(" You chose to attack.\n");
			sleep(1);
			printf("> You jump at the man. He dodges. \n");
			sleep(1);
			printf("> He karate kicks you in the head, you are knocked out...\n");
			sleep(3);
			printf("> Dreaming of a world with harambe,\n");
			printf("> Sunshine lollipops and\n");
			fflush(stdout);			
			sleep(2);
			printf("> rainbows\n> ...\n");
			fflush(stdout);
			sleep(2);			
			printf("> You wake up, the strange man in staring into your face.\n");	
			sleep(1);	
			fflush(stdout);	
			break;
		}
		else if(*input == 'T')
		{	
			printf("> You choose to talk.\n");
			fflush(stdout);
			break;
		}
		else if (checkStandardCommands(input) == 0) {
			printf("> I dont understand, Try again\n> ");
			fflush(stdout);
		}
	}
	//clearScreen();
	printf("> You say 'What am I doing here?'\n");
	sleep(1);
	printf("> He replies 'I found you floating in the sea.\n");
	printf("> I took you in. Healed your wounds, but I found this.'\n");
	sleep(2);
	fflush(stdout);
	sleep(2);
	printf("> He held a piece of metal in the air, it had a red light flashing inside of it.\n");
	sleep(1);
	printf("> You are confused. You have no idea what it is. How do you respond?\n");
	printf("> Type B to say 'None of your business', Type T to say you are confused.\n");
	fflush(stdout);

	while(!responded){
		getInput();
		if(*input == 'B')
		{
			clearScreen();
			printf(" You take a deep breath\n");
			sleep(2);
			printf("> You shout 'It is none of your business. You had no right to take it out'. \n");
			break;
		}
		else if(*input == 'T')
		{
			clearScreen();
			printf(" You are confused\n");
			sleep(2);
			printf("> You say 'I'm not sure what it is. Do you have an idea?'\n");
			break;
		}
		else if (checkStandardCommands(input) == 0) {
			printf("> I do not understand, Try again\n");
		}
		fflush(stdout);
	}
	fflush(stdout);
	sleep(3);
	printf("> The man replies 'I'm a trained doctor, It seemed wrong.\n> I believe it is a tracking device.'\n");
	printf("> You have no idea how it got into you. You have no idea how you got here.\n");
	sleep(3);
	printf("> You say 'Did I have any belongings?'\n");
	printf("> Man replied 'Yes, I found many passports and alot of money,\n> but they were drenched. Here, they have dried up now'\n");
	printf("> You are handed these items. You flick through the passports\n");
	fflush(stdout);
	sleep(1);
	printf("> to find they all have different names. You are confused.\n> You don't even know your name. \n");
	sleep(3);
	printf("> 'Thanks, let me know when we reach shore' you say.\n");
	enterToContinue();
	fflush(stdout);
	printf("> You don't know who you are. You are confused how you got here.\n");
	printf("> This section is over. To be continued... \n");
	fflush(stdout);
	sleep(3);
	printf("> Press enter to play again\n");
	enterToContinue();	
	fflush(stdout);
	//sleep(15);
}


/* Main method, duhh */
int main() {
	while(1){
		welcome();
		printf("> %s, You wake up, all wet and flustered.\n", name);
		printf("> It is dark, it seems you have been injured but are patched up.\n");
		fflush(stdout);
		mainGame();
		enterToContinue();
		fflush(stdout);
	}
	return 0;
}
