#ifndef SCRIPT_H
#define SCRIPT_H

#include "scanner.h"
#include <stdio.h>

#define File FILE

typedef struct Script {
	Scanner *scanner;
	char *commands[];
} Script;

bool tscript_init(Script *script, char filename[]);

bool tscript_exec(Script *script, int OS);

void tscript_close(Script *script);
#endif
