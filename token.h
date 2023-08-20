#ifndef TOKEN_H
#define TOKEN_H

struct token {
	char *class;
	int instance;
	int line;
};

struct parser {
	struct token *aToken;
	int index; 
};

#endif