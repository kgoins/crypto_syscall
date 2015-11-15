#include <stdio.h>
#include "cipher.h"

int main (int argc, char const* argv[]) {
    char msg[] = "Hello World";
    int msgSize = sizeof(msg);

    printf("Size of msg: %d\n", msgSize);

    cipher_t* cipher = createCipher(msg,12,10);
    if (cipher == NULL) {
        printf("Cipher creation failed!\n");
        return -1;
    }

    printf("Size of cipher msg: %d\n", cipher->textLen);
    printf("Cipher text: %s\n", cipher->text);

    destroyCipher(cipher);

    return 0;
}
