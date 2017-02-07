#include "x11.h"
#include "script.h"
#include <string.h>
#include <stdbool.h>

/* interprets the script and saves the xdotool commands into memory in the form of a Batch script
   to run with the system(char *commands) command from stdlib.h */
Bash* save(char **lines, unsigned int length){
	Bash *bash=malloc(sizeof(Bash));

	for(unsigned int i=0;i<length;++i){

	}

	return bash;
}
