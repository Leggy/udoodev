#include <assert.h>
#include "kmp.h"

const char szTest[] = "This is a pie!";

const char szPattern[] = "pie";

void preprocessTest(const size_t testNum, const char *pszPattern, size_t *expected)
{
	fprintf(stdout, "%zu - ", testNum);
	assert(pszPattern);

	size_t len = strlen(pszPattern);

	size_t *table = preprocess(pszPattern);
	for(size_t i = 0; i < len; ++i) {
		if (table[i] != expected[i]) {
			fprintf(stdout, "Failure.\n\n");
			free(table);
			return;
		}
		//fprintf(stdout, "table[%zu] = %zu\n", i, table[i]);
	}
	fprintf(stdout, "Success.\n\n");
	
	free(table);
}

void kmpTest(size_t testNum, const char *text, const char *pattern, size_t expected) {

	fprintf(stdout, "%zu - ", testNum);
	assert(text);	
	assert(pattern);

	size_t kmp = kmpSearch(text, pattern);
	if (kmp == expected) {
		fprintf(stdout, "Success.\n\n");
	} else {
		fprintf(stdout, "Failure.\n\n");
	}

}

int main(int main, char **argv)
{
	fprintf(stdout, "\nKnuth Morris Pratt Implementation Test Suite:\n");
	size_t expected1[] = {0, 0, 0};
	preprocessTest(1, "pie", expected1);
	
	size_t expected2[] = {0, 0, 0, 1, 2, 1, 0, 1};
	preprocessTest(2, "ATTATACA", expected2);
	
	size_t expected3[] = {0, 1, 0, 1, 2, 2};
	preprocessTest(3, "AABAAA", expected3);
	
	size_t expected4[] = {0, 1};
	preprocessTest(4, "BB", expected4);
	
	kmpTest(5, "ABABABC", "ABC", 4);
	kmpTest(6, "ABBABABC", "BB", 1);
	kmpTest(7, "ABABABCA", "BB", 8);
	kmpTest(8, "BA", "BAAAAA", 2);
	
	return 0;
}
