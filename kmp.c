#include <stdlib.h>
#include <assert.h>
#include "kmp.h"

/* Preprocesses the text, creating the overlap table. */
size_t *preprocess(const char *pattern)
{
	size_t tableLength = 0;
	size_t *table = NULL;
	
	if(!pattern || !(tableLength = strlen(pattern)) || !(table = malloc(sizeof(size_t)*tableLength)))
		return NULL;

	table[0] = 0;

	for(size_t i = 1, j = 0; i < tableLength;)
	{
		if(pattern[i] == pattern[j])
			table[i++] = j++ + 1;
		else if(j > 0)
			j = table[j-1];
		else
			table[i++] = 0;
	}

	return table;
}

/* Precondition: text, pattern must NOT be NULL and MUST point to valid strings */
/*Search the text for the first appearance of the pattern.*/
size_t kmpSearch(const char *text, const char *pattern)
{
	size_t m = 0;
	size_t i = 0;
	size_t patternLength = strlen(pattern);
	size_t textLen = strlen(text);
	size_t ret = textLen;

	printf("KMP: %s %s\n", text, pattern);

	size_t *table = preprocess(pattern);

	if(!table)
		return textLen;

	while((m + i) < textLen)
	{
		if(pattern[i] == text[m+i])
		{
			if(i == (patternLength - 1))
			{
				ret = m;
				break;
			}
			++i;
		}
		else
		{
			m += 1 - table[i];
			i = table[i];
		}
	}

	free(table);
	return ret;
}
