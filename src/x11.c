#include "x11.h"
#include "script.h"
#include <string.h>
#include <stdbool.h>

bool run(Script *script){
	for(unsigned int i=0;i<script->length;++i){
		printf("%s\n", script->commands[i]);
	}

	strtok(script->commands[1], "[s+[\".+\"]");
	printf("%s\n", strtok(NULL, "[s+[\".+\"]"));
	return true;
}
