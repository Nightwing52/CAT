#ifdef _Win32
#include "Win32.h"
#else
#include "x11.h"
#endif

#include "scanner.h"
#include "script.h"

bool script_init(Script *script, char filename[]){
	script->scanner=(Scanner *) malloc(sizeof(Scanner));
	if(scnr_init(script->scanner, filename) == false)
		return false;
	else
		return true;
}

bool script_exec(Script *script){
	int curr=-1;
	while(script->scanner->hasNext){
		char *nextLine=scnr_nextLine(script->scanner);
		script->commands=realloc(script->commands, sizeof(script->commands)+sizeof(nextLine));
		script->commands[++curr]=nextLine;
	}

	run(script);

	return true;
}

void script_close(Script *script){
	scnr_close(script->scanner);
	free(script);
}
