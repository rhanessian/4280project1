#include "token.h"

struct parser *createParser (int file);

int getToken (struct token *aToken, struct parser *aParser);

int getInstance (struct parser *aParser, int ind, char *length);

void delete (struct parser *aParser);