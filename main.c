#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "token.h"
#include "testScanner.h"

int main (int argc, const char *argv[]){
	FILE *input;
	struct parser *myParser;
	if ( argc > 2 ) 
    {
        printf( "usage: %s filename", argv[0] );
        return -1;
    }
    else if (argc == 1){
    	printf("Begin inputting tokens (end with EOFtk):\n");
    	input = stdin;
    }
    else 
    {
    	char tempstring[256];
		sprintf(tempstring, "%s.sp23", argv[1]);
        FILE *file = fopen( tempstring, "r" );

        if ( file == 0 )
        {
            printf( "File could not be opened.\n" );
            return -1;
        }
        
        input = file;
    }
    
    myParser = createParser(input);
    if (myParser == NULL) 
    	return -1;
    
    testScanner(myParser);
    
    delete(myParser);
    
    return 0;
}

