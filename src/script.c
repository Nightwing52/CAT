#include "scanner.h"
#include "script.h"

bool tscript_init(Script *script, char filename[]){
	script->scanner=(Scanner *) malloc(sizeof(Scanner));
	if(scnr_init(script->scanner, filename) == false)
		return false;
	else
		return true;
}

bool tscript_exec(Script *script, int OS){
	return true;
}

void tscript_close(Script *script){
	scnr_close(script->scanner);
	free(script);
}
