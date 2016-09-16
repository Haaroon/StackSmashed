/* 
# 	Haaroons CTF - Game Box - 15 September 2016 - v0.1
#   Flag file
*/

#include <stdio.h>

// Colors you fool
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// End colors

void stars(){
	printf(ANSI_COLOR_BLUE "***********************************************" ANSI_COLOR_RESET "\n");
}

/* Main method, duhh */
int main() {
	stars();
	printf(ANSI_COLOR_GREEN";::::,,,::,,;';:,,:,....`.,.,..:';:,.,,:...,,,,\n");
	printf(":,:::,:;':,::,....:,..,,.,,.,,:::,,,..,:,......\n");
	printf(":,::,,;++:,.,,.,,,:,``.,,,:,,,:,,,,,,..,,.```..\n");
	printf(":,,::;+#',..,,,,,.,.```,,:::::;:,:,:,,,,,.````.\n");
	printf(",:;::'++;:,..:,,.`..``.,::;;:::::::::::,,..```.\n");
	printf(";:;;'''':::,,,,...,..,:;,;:;:::::::;;::,,..``..\n");
	printf("';'';;';:::::,,,,:..,:::::;;;;::::::;;:::..```.\n");
	printf("';;;;'''';;::::::,.,;;;'';';;;;':;;+'';;;,````.\n");
	printf(":::;'':::;:::::,`..::''';'::::;+;';;':;'::``...\n");
	printf(":;::;,..:;;;::,`.,:::.:,,,:::,,:,:,::'';;:,`...\n");
	printf(";::,,...:;;;:,..::.,,.,:::;:,::,:;,;:;;;,.:``..\n");
	printf(";.,:,,.,:::;;..,,,,,.:::;;::::::,,::,;;:':.. `.\n");
	printf(":..::,,:;;''..,,,,:::;:';''''':;',..:;:'';,. `.\n");
	printf("::,:::,:;''...:.,:;;:;+'++''+'+''+:;:,`:';,.. .\n");
	printf(":::::::;'':`,:,:;;:';''+++++++'''+':;;;,:;;;` `\n");
	printf("';;:;;;;';``,,::;:;;''+'+##+#+++';';;::;:'':,` \n");
	printf(";;;;;;;;:, .,:::::;:';'+#++#+##+';';::,:;;+;;` \n");
	printf(";;::::::,..,::;:::;:;;:;::,;::;;'''''''.::;:;,`\n");
	printf(";;:,:::::`.,::,:,,.....,,..,.,,::';;;;;:,;;:,,.\n");
	printf(":,,,:,,::`.:::,,,,..,::,,......,.,,,:;;::,;;:;.\n");
	printf(":,,::..:,`,,,:::::::,:::::::,:::,....:,;;:;;;.,\n");
	printf(",,,,::,::`:,,::;'+#+'::;;;:;;;;::,,::,,;;;:;;;.\n");
	printf("::,,::::..::;:''+#@###+'+++++''++++';:;;:;;;:#.\n");
	printf("::,::::,`,;:;;;+#@@@@@@@######@@####+;:;;;;;:+;\n");
	printf("/*;:::,::,.:::;'+####@#@@@@##@@@@@@@@##';';;+;,\n");
	printf(":::,,,,,,:::;++++'+'@@#######@#@;@@@#+'';';';';\n");
	printf(",,,,,,...;:;:'''::;'''+':'+##++#@@+##+'+'''':;:\n");
	printf(",,,,,:,,,::';';':,;'';;,:;:;;;;'+';''''+''''';;\n");
	printf(":::,,,:,,:'':''';;'::,;:,::;,;;:;;::;';':';';;'\n");
	printf(":::::,,,:;'';:;;''':::,:,,:::;;;;::,;'''';';;;'\n");
	printf("::;::,,,:;+';;';;++'::,,:,:::;:;;;';;';''''':;'\n");
	printf(",:;:,,..:;';';:''+;+;:::;;::::::'';';;;'''+':''\n");
	printf("...,:.``,;;;;:;;':'+::,,':;;'::'+';;:;;''+#;::'\n");
	printf("..,,....,:';:;:;:''',,,,,',:;';+'++';;;'+++;:';\n");
	printf(".:,,.,.`,:'';;;:';';,++:.,,,::'++'';:;'+++'':;'\n");
	printf(",::,.,..,;'';;;;';';:+@@,.'#@:;'''';;:;''';;.;;\n");
	printf(",;:,,...,';'';;::'':,'#@@+@@+,:;'';;;:;''+'',::\n");
	printf(",,::,,,,,''';;;;'',;,:'#+###'::;'';;;;'+'';;,;;\n");
	printf("::::,::::'''+:;'',,':,,:,:;:,,';';':;;';'+':;;:\n");
	printf(":;;:;:.::+;'';;;;,,;:,,..,,,,;;:;;;;'';'+'+:::;\n");
	printf(":;;:::,,:;+';'';.,:;;:,,,.,:;;;:;'''+'''++',';;\n");
	printf(";;:::,:::;''+';'::;;;;::::;;;;;;:''++'++''':'';\n");
	printf(";;;::,::,:':'';;;;';';;:::;;'''';'';'+''''';';;\n");
	printf(";;;::;:;;:;;;''';;;;;;:;;;:;;;;'';+'++';'''':;'\n");
	printf(";;;':;;:;;;:;''+;###;,` `;##';''''+'+;;''+'';;;\n");
	printf(";;';:;;;;;;;:''++'''';;:,...:#@#+'+'+'''''+';;;\n");
	printf("';';;;;;;';;;';+'+####@@###'';;'++++''''+++';::\n");
	printf("''''''''''''';;+++#####@@@@####+++'+'+'+++';;;;\n");
	printf("'+;'''''++';;;;++'##+######@##++'+'';'++#';';:;\n");
	printf("''+'+'+++'';::;'+#++####+#####++++;+'+#++;';;;;\n");
	printf("+'+''++'+;;::,:;+###########+###++'+###++;;;:;;\n");
	printf("+''''+'+';:::,:::################'#####+'':;;;'\n");
	printf("'''+++'';:::::::,'#@#######@##########+';'';;';\n");
	printf("'''+''';:::::::::,+#@@@@##@@@######@@+''';'';';\n");
	printf("''''';;:,,::::::,:;'#@@@@@@@#####@#@@'';'''';;;\n");
	printf("'+';:;::::::;:::,:;++###@#@####@#####'';'''';;;\n");
	printf("'';;;:;;;:::::;:,;;++#+#+#####@######'';''';;''\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_YELLOW "***************FLAG:HIDETOSURVIVE**************" ANSI_COLOR_RESET "\n");
	stars();
	fflush(stdout);
	return 0;
}
