/* 
# 	Haaroons CTF - Game Box - 15 September 2016 - v0.1
#	CTF Challenge
#	Objective 
# 		Buffer overflow to get a shell
#		Then do something else to find the flag
#	DO NOT GET ROOT ON THE SERVER THAT IS NOT THE PURPOSE
#	Make then run this on your server with the command
#		ncat -v -l -p 4000 -k -m 10 -e ./main 
#	Have people connect via the command
# 		nc <IP> <PORT>
# 
#  Dont expect this to be anything amazing
#  This is my first actual C program
#  Hip Hip Horay
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Heheheheheh
#pragma check_stack(off)

// Colors you fool
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// End colors

static char input[9];
static char name[150] = "HARAMBEEE";

void printArrow(){
	printf(ANSI_COLOR_YELLOW ">> " ANSI_COLOR_RESET);
}


void stars(){
	printf(ANSI_COLOR_BLUE "************************" ANSI_COLOR_RESET "\n");
}

/* Wait for enter command before continuing */
int enterToContinue(){
	printf(ANSI_COLOR_RED "> Press [Enter] to continue" ANSI_COLOR_RESET "\n");
	printArrow();	
	fflush(stdout);
	int enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

/* clear the damn screen */
void clearScreen() {
	const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
	stars();	
	fflush(stdout);
}

/* Show help menu duhh, why i write this comment baffles me, code is self explanatory */
void helpMenu(){
	stars();
	printf(ANSI_COLOR_RED " HELP MENU" ANSI_COLOR_RESET "\n");
	printf("> Enter H for the help menu\n");
	printf("> Enter I to view your ID\n");
	printf("> This game can only be played using a keyboard\n");
	printf("> Lines starting with > are informational\n");
	fflush(stdout);
	sleep(0);
	printf("> Lines starting with"); 
	printArrow();
	printf(" >> expect your input\n");
	printf(ANSI_COLOR_RED " END HELP MENU" ANSI_COLOR_RESET "\n");
	stars();
	fflush(stdout);
	sleep(0);
}

/* Get name from user */
void setName(){
	printf("> Please enter your name (Max 8 characters) \n> below followed by [Enter] key:\n");
	printArrow();
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
	printf(ANSI_COLOR_BLUE  "**************************************************************************" ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	"    )                                                       (     "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	" ( /(                                (          (     *   ) )\\ )  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	" )\\())    )     )  (                 )\\         )\\  ` )  /((()/(  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	"((_)\\  ( /(  ( /(  )(    (    (    (((_) (    (((_)  ( )(_))/(_)) "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	" _((_) )(_)) )(_))(()\\   )\\   )\\   )\\ )  )\\   )\\___ (_(_())(_))_| "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"| || |((_)_ ((_)_  ((_) ((_) ((_) _(_/( ((_) ((/ __||_   _|| |_   "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"| __ |/ _` |/ _` || '_|/ _ \\/ _ \\| ' \\))(_-<  | (__   | |  | __|  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"|_||_(\\__,_|\\__,_||_|  \\___/\\___/|_(|_| /__/   \\___|  |_|  |_|    "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	"     )\\ )       )     )      (   ( )\\          )                  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	"    (()/(    ( /(    (      ))\\  )((_)  (   ( /(                  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED	"     /(_))_  )(_))   )\\  ' /((_)((_)_   )\\  )\\())                 "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"    (_)) __|((_)_  _((_)) (_))   | _ ) ((_)((_)\\                  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"      | (_ |/ _` || '  \\()/ -_)  | _ \\/ _ \\ \\ /                  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW"       \\___|\\__,_||_|_|_| \\___|  |___/\\___//_\\_\\                  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_BLUE  "**************************************************************************" ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_RED""ANSI_COLOR_RESET "\n");                                                                  
	//stars();
	printf("> Welcome to my CTF challenge\n");
	printf("> The aim is simple, find the flag which is on this box\n");
	printf(ANSI_COLOR_RED "do not priv esc!" ANSI_COLOR_RESET "\n");
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
	stars();
}

int getInput()
{
	printArrow();
	fflush(stdout);
	scanf("%s", input);
	fflush(stdout);
  	return 1;
}

void showID(char* input){
 	//printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
	//fflush(stdout);
	stars();
	printf(ANSI_COLOR_YELLOW " _____  ______    "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW "|_   _||_   _ `.  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW "  | |    | | `. \\ "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW "  | |    | |  | | "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW " _| |_  _| |_.' / "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW "|_____||______.'  "ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW "                  "ANSI_COLOR_RESET "\n");                  
	fflush(stdout);
 	char names[150];
    strcpy(names, input);
    printf("Name: %s\n", names);
 	//printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
	stars();		
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
	printf(ANSI_COLOR_CYAN "> Type L for Left Door, Type R for Right door" ANSI_COLOR_RESET "\n");
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
			printf(ANSI_COLOR_RED "> I do not understand, Try again" ANSI_COLOR_RESET "\n");                  
		}
		fflush(stdout);
	}
	fflush(stdout);
	sleep(1);
	printf("> A man approches with a knife in hand. What do you do?\n");
	printf(ANSI_COLOR_CYAN "> Type A to attack, Type T to talk." ANSI_COLOR_RESET "\n");
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
			printf(ANSI_COLOR_YELLOW "> Dreaming of a world with harambe,\n> Sunshine lollipops and\n> rainbows\n> ..." ANSI_COLOR_RESET "\n");
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
			printf(ANSI_COLOR_RED "> I do not understand, Try again" ANSI_COLOR_RESET "\n");              
			fflush(stdout);
		}
	}
	//clearScreen();
	printf("> You say ");
	printf(ANSI_COLOR_YELLOW "'What am I doing here?'" ANSI_COLOR_RESET "\n");              
	sleep(1);
	printf("> He replies ");
	printf(ANSI_COLOR_GREEN "'I found you floating in the sea.\n> I took you in. Healed your wounds, but I found this.'"ANSI_COLOR_RESET "\n");	
	sleep(2);
	fflush(stdout);
	sleep(2);
	printf("> He held a piece of metal in the air, it had a ");
	printf(ANSI_COLOR_RED "red" ANSI_COLOR_RESET " light flashing inside of it" "\n");	
	sleep(1);
	printf("> You are confused. You have no idea what it is. How do you respond?\n");
	printf(ANSI_COLOR_CYAN "> Type B to say 'None of your business', Type T to say 'You are confused.'" ANSI_COLOR_RESET "\n");	
	fflush(stdout);

	while(!responded){
		getInput();
		if(*input == 'B')
		{
			clearScreen();
			printf(" You take a deep breath\n");
			sleep(2);
			printf("> You shout ");
			printf(ANSI_COLOR_YELLOW "'It is none of your business. You had no right to take it out.'" ANSI_COLOR_RESET "\n");         
			break;
		}
		else if(*input == 'T')
		{
			clearScreen();
			printf(" You are confused\n");
			sleep(2);
			printf("> You say ");
			printf(ANSI_COLOR_YELLOW "'I'm not sure what it is. Do you have an idea?'" ANSI_COLOR_RESET "\n");
			break;
		}
		else if (checkStandardCommands(input) == 0) {
			printf(ANSI_COLOR_RED "> I do not understand, Try again" ANSI_COLOR_RESET "\n");              
		}
		fflush(stdout);
	}
	fflush(stdout);
	sleep(3);
	printf("> The man replies "); 
	printf(ANSI_COLOR_GREEN "'Sorry for taking it out, the device seemed wrong.\n> I believe it is a tracking chip.'\n" ANSI_COLOR_RESET "\n");		
	printf("> You have no idea how it got into you. You have no idea how you got here.\n");
	sleep(3);
	printf("> You say ");
	printf(ANSI_COLOR_YELLOW "'Did I have any belongings?'" ANSI_COLOR_RESET "\n");    
	printf("> Man replied ");
	printf(ANSI_COLOR_GREEN "'Yes, I found many passports and alot of money,\n> but they were drenched. Here, they have dried up now.'" ANSI_COLOR_RESET "\n");  
	printf("> You are handed these items. You flick through the passports\n");
	fflush(stdout);
	sleep(1);
	printf("> to find they all have different names. You are confused.\n> You don't even know your name. \n");
	sleep(3);
	printf("> You say "); 
	printf(ANSI_COLOR_YELLOW "'Thanks, let me know when we reach shore'" ANSI_COLOR_RESET "\n"); 
	enterToContinue();
	fflush(stdout);
	printf("> You don't know who you are. You are confused how you got here.\n");
	printf("> This section is over. Chapter 2 as DLC coming SOON! \n > To be continued... \n");
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
		//stars();
		welcome();
		printf("> %s, You wake up, all wet and flustered.\n", name);
		printf("> It is dark, it seems you have been injured but are patched up.\n");
		fflush(stdout);
		mainGame();
		enterToContinue();
		stars();
		fflush(stdout);
	}
	return 0;
}
