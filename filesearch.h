#include "kmp.h"
#include <string.h>
#include <stdio.h>

/*Linked List implementation of a dictionary*/
typedef struct dict {
    struct dict* next;
    char* word;
    size_t num;
} dictionary;

/* FileSearch takes two strings (char *) as input, the first being a filename,
   the second being the text to search through. */
   
size_t fileSearch(const char* filename, const char* text, dictionary* dict);
size_t subSearch(char* text, const char* pattern);


