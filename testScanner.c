#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "token.h"

int testScanner (struct parser *aParser){
	struct token tk;
	int lineNum = 0;
	int val;
	
	printf("\n{Token ID, Instance, Line Number}");
	
	do {
		val = getToken(&tk, aParser);
		if (val >= 0) {
			printf ("{%s, %d, %d}\n", tk.class, tk.instance, tk.line);
			lineNum = tk.line;
		}
		if (val < 0) {
			printf ("\n{EOFtk, 0, %d}\n", lineNum);
			break;
		}
	} while (val >= 0);
	
	return 0;
}

