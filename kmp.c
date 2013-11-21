#include <stdlib.h>

#include "kmp.h"

/* Preprocesses the text, creating the overlap table. */
size_t *preprocess(const char *pattern)
{
	size_t tableLength = 0;
	size_t *table = NULL;
	size_t byteSized = 0;
	
	if(!pattern || !(tableLength = strlen(pattern), byteSized = sizeof(size_t)*tableLength) || !(table = malloc(byteSized)))
		return NULL;

	memset(table, 0, byteSized);
	table[0] = table[1] = 0;

	/* Until overlap can be extended */
	for(size_t i = 1, v; i < tableLength; ++i)
	{
		v = table[i];
		/* Finding the next largest precomputed overlap */
		for(; (pattern[v] != pattern[i]) && v; v = table[v]);

		if(pattern[v] == pattern[i])
			table[i+1] = v + 1; /* Extend current overlap */
		
	}

	/* This is a HACK */
	memmove(table, &table[1], byteSized);
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
