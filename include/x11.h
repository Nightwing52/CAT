#ifndef X11_H
#define X11_H

#include "script.h"
#include <stdbool.h>

typedef struct Bash{
	char **commands; //in xdotool form
} Bash;

Bash* save(char **lines, unsigned int length);

bool run(Bash *bash);

#endif
