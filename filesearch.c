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
    
    dict = malloc(sizeof(dictionary));
    dictionary* dictTemp = dict;
    
    char* line = NULL;
    size_t len = 0;
    
    int occurances;
    
    while(getline(&line, &len, file) != -1) {
        occurances = subSearch(line, text);
        
        /*dictTemp->word = line;
        dictTemp->num = occurances;
        dictTemp->next = malloc(sizeof(dictionary));
        dictTemp = dictTemp->next;*/
        printf("%s  %d\n", line, occurances);
    }
    printf("Closing file\n");
    fclose(file);
    return 0;
}

/* Returns the number of occurances of the pattern in the text. */
int subSearch(char* text, char* pattern) {
    int occurances = 0;
    char* temp = text;
    int index = 0;
    
    printf("subsearch: \n");
    printf("temp: %s\n", temp);
    printf("kmp: %d\n", kmpSearch(temp, pattern));
    while ((index = kmpSearch(temp, pattern)) != -1) {
        printf("index: %d\n", index);
        occurances += 1;
        if (strlen(pattern) + index >= strlen(temp)) {
            printf("Breaking\n");
            break;
        } else {
            temp += strlen(pattern) + index;
        }
    }
    return occurances;
}
