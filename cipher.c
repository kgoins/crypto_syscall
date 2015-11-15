#include "cipher.h"

cipher_t* createCipher(char* msg, int lkey, int nkey) {
    int i = 0;
    cipher_t* cipher = (cipher_t*) malloc(sizeof(cipher_t));
    if (cipher == NULL)
        return NULL;

    /* process input */
    cipher->charKey = lkey;
    cipher->numKey = nkey;

    while (msg[i] != '\0')
        ++i;

    /* sanitize msg (++i accounts for null terminator) */
    if(++i > TEXT_MAX) {
        i = TEXT_MAX;
        msg[i] = '\0';
    }

    cipher->textLen = i;

    cipher->text = (char*) malloc(sizeof(cipher->textLen));
    if (cipher == NULL)
        return NULL;

    for (i = 0; i < cipher->textLen; i++)
        cipher->text[i] = msg[i];

    return cipher;
}

void destroyCipher(cipher_t* cipher) {
    free(cipher->text);
    free(cipher);
}
