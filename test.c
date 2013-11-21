#include "kmp.h"
#include "filesearch.h"
#include <stdio.h>


void kmpTest1(void);
void kmpTest2(void);
void kmpTest3(void);
void kmpTest4(void);

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


int main(int argc, char** argv) {
    kmpTest1();
    kmpTest2();
    kmpTest3();
    kmpTest4();
    kmpTest4();
    
    printf("\n");
    
    //subSearchTest1();
    subSearchTest2();
    subSearchTest3();
    
    printf("\n");
    
    fileSearchTest1();
    fileSearchTest2();
    fileSearchTest3();
    fileSearchTest4();
    fileSearchTest5();
    //fileSearchTest6();
    //fileSearchTest7();
    
    printf("\nDone\n");
   
    return 0;
}

void kmpTest1() {
    char* pattern = "ABCD";
    char* string = "012345ABCDEFG";
    
    if (kmpSearch(string, pattern) == 6) {
        printf("1 - KMP Success\n");
    } else {
        printf("1 - KMP Failure\n");
    }
}


void kmpTest2() {
    char* pattern = "ABCD";
    char* string = "ABCABCABCDABC";
    
    if (kmpSearch(string, pattern) == 6) {
        printf("2 - KMP Success\n");
    } else {
        printf("2 - KMP Failure\n");
    }
}

void kmpTest3() {
    char* pattern = "ABCD";
    char* string = "ABABCABCABCDABC";
    
    if (kmpSearch(string, pattern) == 8) {
        printf("3 - KMP Success\n");
    } else {
        printf("3 - KMP Failure\n");
    }
}

void kmpTest4() {
    char* pattern = "BB";
    char* string = "ABABABC";
    
    if (kmpSearch(string, pattern) == -1) {
        printf("4 - KMP Success\n");
    } else {
        printf("4 - KMP Failure\n");
    }
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

void subSearchTest1() {
    if (subSearch("ABABABC", "AB") == 3) {
        printf("1 - SubSearch Success\n");
    } else {
        printf("1 - SubSearch Failure\n");
    }
}

void subSearchTest2() {
if (subSearch("ABABABC", "ABC") == 1) {
        printf("2 - SubSearch Success\n");
    } else {
        printf("2 - SubSearch Failure\n");
    }
}

void subSearchTest3() {
    printf("\n\nIn 3\n");
    if (subSearch("ABABABC", "BB") == 0) {
        printf("3 - SubSearch Success\n");
    } else {
        printf("3 - SubSearch Failure\n");
    }


}
