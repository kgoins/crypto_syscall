#include <stdio.h>
#include <stdlib.h>

#include "cipher.h"

/* error codes */
#define MALLOC_ERR 1
#define TEST_FAIL 2


int run_test (char* msg, int lkey, int nkey) {
    char* msgCopy;
    int i = 0, msgLen = 0, testErr = 0;

    /* get length and sanitize msg */
    msgLen = processInput(msg);

    /* copy sanitized msg to msgCopy */
    msgCopy = (char*) malloc(msgLen * sizeof(char));
    if(msgCopy == NULL)
        return MALLOC_ERR;

    while(msg[i] != '\0')
        msgCopy[i] = msg[i];
    msgCopy[msgLen] = '\0';
    
    /* run encrypt and decrypt */
    printf("plaintext message: %s\n", msg);

    cipher(msg, lkey, nkey);
    printf("encrypted message: %s\n", msg);

    cipher(msg, -lkey, -nkey);
    printf("decrypted message: %s\n", msg);

    /* compare decrypted and origional msg */
    i = 0;
    while(msg[i] != '\0') {
        if (msg[i] != msgCopy[i]) {
            testErr = TEST_FAIL;
            break;
        } else ++i;
    }

    free(msgCopy);
    return testErr;
}

int main (int argc, char const* argv[]) {
    int testErr;

    /* test keys */
    int lkey = 'B';
    int nkey = 'B';

    /* test strings */
    /* char subTest[] = "Hello World!"; */
    char transTest_0[] = "Hell"; /* single quad */

    /* run tests */
    testErr = run_test(transTest_0, lkey, nkey);

    /* handle errors */
    switch(testErr) {
        case 0:
            printf("Test Passed!\n");
            break;
        case MALLOC_ERR:
            printf("Malloc Error\n");
            break;
        case TEST_FAIL:
            printf("Test Failed\n");
            break;
    }

    return 0;
}
