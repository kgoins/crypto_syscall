#ifndef CIPHER_H
#define CIPHER_H

#include <stdio.h>

#define CIPHER_TEXT_MAX 1025

int cipher(char* text, int lkey, int nkey);

/* encryption algorithms */
void sub(char* text, int lkey, int nkey, int textLength);
void trans(char* text, int textLength);

#endif
