#include "kmp.h"

/*Preprocesses the text, creating the overlap table.*/
int* preprocess(char* pattern) {
    int tableLength = strlen(pattern);
    int* table = malloc(sizeof(int) * tableLength);
    //Pattern[1] cannot have a proper prefix or suffix.
    table[0] = 0;
    table[1] = 0;

    char c;
    int v;
    for (int k = 1; k < tableLength; k++) {
        //The current character, and overlap so far.
        c = pattern[k];
        v = table[k];
        
        //Until overlap can be extended.
        while (pattern[v] != c && v != 0) {
            //Finding the next largest precomputed overlap.
            v = table[v];
        }

        if (pattern[v] == c) {
            //Extend current overlap.
            table[k + 1] = v + 1;
        } else {
            //No overlap exists.
            table[k + 1] = 0;
        }
    }
    return table;
}

/*Search the text for the first appearance of the pattern.*/
int search(char* text, char* pattern) {
    int m = 0;
    int i = 0;
    int* table = preprocess(pattern);
    
    while (m + i < strlen(text)) {
        if (pattern[i] == text[m + i]) {
            if (i == strlen(pattern) - 1) {
                return m;
            }
            i++;        
        } else {
            m = m + 1 - table[i];
            if (table[i] > -1) {
                i = table[i];
            } else {
                i = 0;
            }
        } 
    }
    return strlen(text);
}