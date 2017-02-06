#ifndef SCRIPT_H
#define SCRIPT_H

#include "scanner.h"
#include <stdio.h>

#define File FILE

typedef struct Script {
	Scanner *scanner;
	char **commands;
} Script;

bool script_init(Script *script, char filename[]);

bool script_exec(Script *script);

void script_close(Script *script);
#endif
