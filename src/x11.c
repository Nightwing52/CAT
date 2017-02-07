#include "x11.h"
#include "script.h"
#include <string.h>
#include <stdbool.h>

bool run(char *line){
	char *command=strtok(line, "[s+[\".+\"]");

	if(command == NULL){
		free(command);
		return true; //empty line
	}

	char **arguments=NULL;
	unsigned int numArgs=0;
	char *nextToken=NULL;
	nextToken=strtok(NULL, "[s+[\".+\"]");
	while(nextToken != NULL){
		arguments=realloc(arguments, sizeof(arguments)+sizeof(char *));
		strcpy(arguments[numArgs], nextToken);
		++numArgs;
	}
	free(nextToken);

	for(int i=0;i<numArgs;i++){
		printf("%s\n", arguments[i]);
	}

	return true;
}
