#ifndef SCRIPT_H
#define SCRIPT_H

#include "scanner.h"
#include <stdio.h>

#define File FILE

typedef struct Script {
	Scanner *scanner;
	char *shortcut;
} Script;

bool script_load(Script *script, char *filename);

bool script_exec(Script *script);
#endif
