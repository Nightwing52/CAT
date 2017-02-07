#ifdef _Win32
#include "Win32.h"
#else
#include "x11.h"
#endif

#include "scanner.h"
#include "script.h"
#include <string.h>
#include <stdbool.h>

bool script_load(Script *script, char *filename){
	/* setup */
	script->scanner=malloc(sizeof(Scanner));
	if(scnr_init(script->scanner, filename) == false)
		return false;

	/* validating the script and getting the keyboard shortcut to activate it */
	if(script->scanner->hasNext){
		char *token=scnr_nextLine(script->scanner);
		strtok(token, "[s+[\".+\"]");
		printf("%s %d\n", token, (int)strlen(token));
		if(strcmp(token, "on ") == 0)
			script->shortcut=strtok(NULL, "[s+[s+\".+\"s+]");
		else{
			printf("There is no keyboard shortcut for the script!\n");
			return false;
		}
	}
	else{
		scnr_close(script->scanner);
		printf("%s is an empty file!\n", filename);
	}

	/* reading script into memory */
	unsigned int size=0;
	char **commands=malloc(sizeof(char *));
	/* seg fault loop */
	while(script->scanner->hasNext){
		commands=realloc(commands, sizeof(commands)+sizeof(char *)*size);
		char *currLine=scnr_nextLine(script->scanner);
		commands[size]=currLine;
		size++;
	}

	/* saving the commands for future calling */
	save(commands, size);

	/* cleaning up */
	scnr_close(script->scanner);
	return true;
}

bool script_exec(Script *script){
	return true;
}
