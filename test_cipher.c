#include <stdio.h>
#include "cipher.h"

int main (int argc, char const* argv[]) {
    char msg[] = "Hello World";
    int lkey = 'B';
    int nkey = 'B';

    printf("plaintext message: %s\n", msg);

    cipher(msg, lkey, nkey);
    printf("encrypted message: %s\n", msg);

    cipher(msg, -lkey, -nkey);
    printf("decrypted message: %s\n", msg);

    return 0;
}
