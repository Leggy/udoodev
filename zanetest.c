#include <assert.h>
#include "kmp.h"

const char szTest[] = "This is a pie!";

const char szPattern[] = "pie";

void preprocessTest(const char *pszPattern)
{
	assert(pszPattern);

	size_t len = strlen(pszPattern);
	
	fprintf(stderr, "Preprocessing \"%s\", length %zu\n", pszPattern, len);

	size_t *table = preprocess(pszPattern);
	for(size_t i = 0; i < len; ++i)
		fprintf(stderr, "table[%zu] = %zu\n", i, table[i]);
		
	fprintf(stderr, "\n");
	
	free(table);
}

int main(int main, char **argv)
{
	preprocessTest("pie");
	preprocessTest("ATTATACA");
	preprocessTest("AABAAA");
	preprocessTest("BB");
	return 0;
}
