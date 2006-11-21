#include "filesearch.h"

/*  FileSearch takes two strings (char *) and a dictionary pointer as input, the
    first string being a filename, the second being the text to search through.
    The dictionary pointer should point to NULL, it is allocated in this scope.
   
    Return Values:
        0: Working correctly
        1: filename or text NULL
        2: filename invalid
         */

int fileSearch(char* filename, char* text, dictionary* dict) {
    if (filename == NULL || text == NULL || strlen(filename) == 0
            || strlen(text) == 0) {
        return 1;
    }
    
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        return 2;
    }
    
    
    return 0;
}
