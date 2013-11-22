#include "kmp.h"
#include "filesearch.h"
#include <assert.h>


void fileSearchTest1(void);
void fileSearchTest2(void);
void fileSearchTest3(void);
void fileSearchTest4(void);
void fileSearchTest5(void);
void fileSearchTest6(void);
void fileSearchTest7(void);

void subSearchTest1(void);
void subSearchTest2(void);
void subSearchTest3(void);

void subSearchTest(const size_t testNum, char *text, const char *pattern, size_t expected) {
	fprintf(stdout, "%zu - ", testNum);
	
	assert(text);
	assert(pattern);
	
	size_t occurances = subSearch(text, pattern);
	if (occurances == expected) {
		fprintf(stdout, "Success.\n\n");
	} else {
		fprintf(stdout, "Failure.\n\n");
	}


}


int main(int argc, char** argv) {
	fprintf(stdout, "\nFile Search Test Suite:\n");
	
	subSearchTest(1, "ABABABC", "AB", 3);
	subSearchTest(2, "ABABABC", "ABC", 1);
	subSearchTest(3, "ABABABC", "BB", 0);
	subSearchTest(4, "The cat in a hat.", "a", 3);
	subSearchTest(5, "Short Text.", "Longer Pattern", 0);

   
    return 0;
}

void fileSearchTest1() {

    if (fileSearch(NULL, "Hi", NULL) == 1) {
        printf("1 - FileSearch Success\n");
    } else {
        printf("1 - FileSearch Failure\n");
    }
}

void fileSearchTest2() {

    if (fileSearch("Hi", NULL, NULL) == 1) {
        printf("2 - FileSearch Success\n");
    } else {
        printf("2 - FileSearch Failure\n");
    }
}

void fileSearchTest3() {

    if (fileSearch("", "Hi", NULL) == 1) {
        printf("3 - FileSearch Success\n");
    } else {
        printf("3 - FileSearch Failure\n");
    }
}

void fileSearchTest4() {

    if (fileSearch("Hi", "", NULL) == 1) {
        printf("4 - FileSearch Success\n");
    } else {
        printf("4 - FileSearch Failure\n");
    }
}

void fileSearchTest5() {

    if (fileSearch("invalidFile", "Text", NULL) == 2) {
        printf("5 - FileSearch Success\n");
    } else {
        printf("5 - FileSearch Failure\n");
    }
}

void fileSearchTest6() {
    printf("6 - \n");
    fileSearch("testFile", "ABABABC", NULL);
}

void fileSearchTest7() {

    if (fileSearch("testFile", "Text", NULL) == 0) {
        printf("7 - FileSearch Success\n");
    } else {
        printf("7 - FileSearch Failure\n");
    }
}


