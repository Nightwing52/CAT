#ifdef _WIN32
#include "Win32.h"
#define WindowsOS 1
#define ClientOS WindowsOS
#else
#include "x11.h"
#define LinuxOS 2
#define ClientOS LinuxOS
#endif

#include "script.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
	/* interpret script */
	Script *script=(Script *) malloc(sizeof(Script));
	printf("Enter the filename for your script.\n");
	char *filename=(char *) malloc(sizeof(char)*32);
	scanf("%s", filename);
	tscript_init(script, filename);
	free(filename);

	/* execute script */
    tscript_exec(script, ClientOS);

	return 0;
}
