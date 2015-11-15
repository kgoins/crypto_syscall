#include "cipher.h"

void sub(cipher_t* cipher) {
    char* c = cipher->text;
    int i;
    char x, offset;

    char xUpper = 'A' + (cipher->charKey % 26) + 26;
    char xLower= 'a' + (cipher->charKey % 26) + 26;
    char xNum= '0' + (cipher->numKey % 10) + 10;

    char charOffsetFlag = (cipher->charKey < 0) && (cipher->charKey & 0x1);

    for (i = 0; i < cipher->textLen; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z') {
            x = (c[i] - xUpper) % 26;
            offset = (charOffsetFlag) ? 
                (((x - 'A') & 0x1) ? 'A' : 'a') :
                (((x - 'A') & 0x1) ? 'a' : 'A') ;
            c[i] = x + offset;
        }
        else if(c[i] >= 'a' && c[i] <= 'z') {
            x = (c[i] - xLower) % 26;
            offset = (charOffsetFlag) ? 
                (((x - 'A') & 0x1) ? 'a' : 'A') :
                (((x - 'A') & 0x1) ? 'A' : 'a') ;
            c[i] = x + offset;
        }
        else if(c[i] >= '0' && c[i] <= '9') 
            c[i] = ((c[i] - xNum) % 10) + '0';
        else
            continue;
    }
}
