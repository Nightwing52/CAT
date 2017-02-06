#ifdef _WIN32
#include "windows.h"
#else
#include "x11.h"
#endif

#include "script.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
	/* load script */
	Script *script=(Script *) malloc(sizeof(Script));
	printf("Enter the filename for your script.\n");
	char *filename=(char *) malloc(sizeof(char)*32);
	scanf("%s", filename);
	script_init(script, filename);
	free(filename);

	/* execute script */
    script_exec(script);

	return 0;
}
