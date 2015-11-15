#ifndef CIPHER_H
#define CIPHER_H

#include <stdlib.h>

#define TEXT_MAX 1025

/* global vars */
typedef struct {
    char* text;
    int textLen;
    int charKey, numKey;
} cipher_t;
 
cipher_t* createCipher(char* msg, int lkey, int nkey);
void destroyCipher(cipher_t* cipher);

#endif
