#ifdef _Win32
#include "Win32.h"
#else
#include "x11.h"
#endif

#include "scanner.h"
#include "script.h"
#include <string.h>

bool script_init(Script *script, char filename[]){
	script->scanner=(Scanner *) malloc(sizeof(Scanner));
	if(scnr_init(script->scanner, filename) == false)
		return false;

	if(script->scanner->hasNext){
		char *firstLine=scnr_nextLine(script->scanner);
		script->commands=malloc(sizeof(char *));
		script->commands[0]=firstLine;
		script->length=1;
	}

	unsigned int curr=0;
	while(script->scanner->hasNext){
		script->length+=1;
		char *nextLine=scnr_nextLine(script->scanner);
		script->commands=realloc(script->commands, sizeof(char *)*script->length);
		script->commands[++curr]=nextLine;
	}
	return true;
}

bool script_exec(Script *script){
	run(script);

	return true;
}

void script_close(Script *script){
	scnr_close(script->scanner);
	free(script);
}
