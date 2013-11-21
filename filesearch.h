#include "kmp.h"
#include <string.h>
#include <stdio.h>

/*Linked List implementation of a dictionary*/
typedef struct dict {
    struct dict* next;
    char* word;
    int num;
} dictionary;

/* FileSearch takes two strings (char *) as input, the first being a filename,
   the second being the text to search through. */
   
int fileSearch(char* filename, char* text, dictionary* dict);
int subSearch(char* text, char* pattern);


