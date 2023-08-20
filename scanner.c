#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "token.h"

struct parser *createParser (int inputFile) {
	char buf[256];
	struct parser *aParser = calloc(1, sizeof(struct parser));
	int count = 0;
	char *ptr = calloc(1, 6000000);
	while (*ptr) {
		memset(buf, 0, sizeof(buf));
		while (*ptr && !isspace(*ptr))
			ptr++;
		++count;
	}
	
	aParser -> aToken = calloc(sizeof(struct token), count);
	
	free(ptr);
	return aParser;
}

int getToken (struct token *aToken, struct parser *aParser) {
	int ind = aParser -> index++;
	if (!aParser -> aToken[ind].class)
		return -1;
	
	aToken -> class = aParser -> aToken[ind].class;
	aToken -> instance = aParser -> aToken[ind].instance;
	aToken -> line = aParser -> aToken[ind].line;
	
	return 0;
}

int getInstance (struct parser *aParser, int ind, char *length) {
	int numChars = (int)strlen(length);
	int inst = 0;
	
	if (ind == 0)
		return 0;
		
	for (int i = 0; i < ind; i++) {
		if ((int)strlen(aParser -> aToken[i].class) == numChars &&
			!strncmp(length, aParser -> aToken[i].class, numChars))
			inst++;
	}
	
	return inst;
}

void delete (struct parser *aParser) {
	free (aParser -> aToken);
	free (aParser);
}

