#include "filesearch.h"

/*  FileSearch takes two strings (char *) and a dictionary posize_ter as input, the
    first string being a filename, the second being the text to search through.
    The dictionary posize_ter should posize_t to NULL, it is allocated in this scope.
   
    Return Values:
        0: Working correctly
        1: filename or text NULL
        2: filename invalid
         */

size_t fileSearch(const char* filename, const char* text, dictionary* dict) {
    if (filename == NULL || text == NULL || strlen(filename) == 0
            || strlen(text) == 0) {
        return 1;
    }
    
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        return 2;
    }
    
    dict = malloc(sizeof(dictionary));
    dictionary* dictTemp = dict;
    
    char* line = NULL;
    size_t len = 0;
    
    size_t occurances;
    
    while(getline(&line, &len, file) != -1) {
        occurances = subSearch(line, text);
        
        /*dictTemp->word = line;
        dictTemp->num = occurances;
        dictTemp->next = malloc(sizeof(dictionary));
        dictTemp = dictTemp->next;*/
        printf("%s  %s  %zu\n", line, text, occurances);
    }
    printf("Closing file\n");
    fclose(file);
    return 0;
}

/* Returns the number of occurances of the pattern in the text. */
size_t subSearch(char* text, const char* pattern) {
    size_t occurances = 0;
    char* temp = text;
    size_t index = 0;
    
    while ((index = kmpSearch(temp, pattern)) != strlen(temp)) {
        occurances += 1;
        if (strlen(pattern) + index >= strlen(temp)) {
            break;
        } else {
            temp += strlen(pattern) + index;
        }
    }
    return occurances;
}
