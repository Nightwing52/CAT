#include "x11.h"
#include "script.h"
#include <stdbool.h>

bool run(Script *script){
	for(unsigned int i=0;i<script->length;++i){
		printf("%s\n", script->commands[i]);
	}

	return true;
}
