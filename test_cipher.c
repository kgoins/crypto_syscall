#include <stdio.h>
#include <stdlib.h>

#include "cipher.h"

/* error codes */
#define MALLOC_ERR 1
#define TEST_FAIL 2
#define LENGTH_MISMATCH 3


void run_test (char* msg, int lkey, int nkey) {
    char* msgCopy = NULL;
    int i = 0;
    int msgOrigLen = 0, msgEncLen = 0, msgDecLen = 0;
    int testErr = 0;

    /* get length and sanitize msg */
    msgOrigLen = processInput(msg);

    /* copy sanitized msg to msgCopy */
    msgCopy = (char*) malloc(msgOrigLen * sizeof(char));
    if(msgCopy == NULL) {
        printf("Malloc Error!\n");
        return;
    }

    i = 0;
    while(msg[i] != '\0') {
        msgCopy[i] = msg[i];
        ++i;
    }
    msgCopy[msgOrigLen] = '\0';
    
    /* run encrypt and decrypt */
    printf("plaintext message: %s\n", msg);
    printf("size: %d\n", msgOrigLen);
    printf("\n");

    printf("Enryption system errors:\n");
    msgEncLen = cipher(msg, lkey, nkey);
    printf("encrypted message: %s\n", msg);
    printf("size: %d\n", msgEncLen);
    printf("\n");

    printf("Decryption system errors:\n");
    msgDecLen = cipher(msg, -lkey, -nkey);
    printf("decrypted message: %s\n", msg);
    printf("size: %d\n", msgDecLen);

    /* test message lengths to origional */
    if (msgEncLen != msgOrigLen || msgDecLen != msgOrigLen) {
        testErr = LENGTH_MISMATCH;
        goto handle_errs;
    }

    /* compare decrypted and origional msg */
    printf("Origional message: %s\n", msgCopy);

    i = 0;
    while(msg[i] != '\0') {
        if (msg[i] != msgCopy[i]) {
            testErr = TEST_FAIL;
            break;
        } else ++i;
    }

    /* handle errors */
handle_errs:
    switch(testErr) {
        case 0:
            printf("Test Passed!\n");
            break;
        case TEST_FAIL:
            printf("Test Failed: Strings not equal\n");
            break;
        case LENGTH_MISMATCH:
            printf("Test Failed: Length mismatch\n");
            break;
    }


    printf("\n");
    free(msgCopy);
}

int main (int argc, char const* argv[]) {
    /* test keys */
    int lkey = 'B';
    int nkey = 'B';

    /* test strings */
    char subTest[] = "Hello World!";
    char transTest_0[] = "Hell";
    char transTest_1[] = "HHHello";

    /* run tests */
    printf("Sub alg test on Hello World!\n");
    /* run_test(subTest, lkey, nkey); */

    printf("Test trans alg with only one quad\n");
    /* run_test(transTest_0, lkey, nkey); */

    printf("Trans alg test: 3 char last quad \n");
    run_test(transTest_1, lkey, nkey);


    return 0;
}
