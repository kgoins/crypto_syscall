#include "cipher.h"

int cipher (char* text, int lkey, int nkey) {   
    int textLength = 0;

    /* calculate text length */
    while(text[textLength] != '\0')
        ++textLength;

    /* account for ending null terminator */
    textLength += 1;

    /* truncate string */
    if(textLength > CIPHER_TEXT_MAX) {
        textLength = CIPHER_TEXT_MAX;
        text[textLength] = '\0';
    }

    /* run encryption algorithms */
    sub(text, lkey, nkey, textLength);
    trans(text, textLength);

    return textLength;
}

void sub (char* text, int lkey, int nkey, int textLength) {
    int i, x, offset;

    int lkeyHash = (lkey % 26) + 26;
    int nkeyHash = (nkey % 10) + 10;

    int decrypt = ( (lkey < 0) && (lkey & 0x1) );

    for (i = 0; i < textLength; i++) {
        /* text[i] is upper case letter */
        if(text[i] >= 'A' && text[i] <= 'Z') {
            printf("%c is an upper case letter\n", text[i]);
            x = (text[i] - 'A' + lkeyHash) % 26;

            if (decrypt)
                offset = ((x-'A') & 0x1) ? 'A':'a';
            else
                offset = ((x-'A') & 0x1) ? 'a':'A';

            text[i] = x + offset;
        }
        /* text[i] is lower case letter */
        else if(text[i] >= 'a' && text[i] <= 'z') {
            printf("%c is a lower case letter\n", text[i]);
            x = (text[i] - 'a' + lkeyHash) % 26;
            offset = (decrypt) ? 
                ( ( (x - 'A') & 0x1 ) ? 'a' : 'A' ) :
                ( ( (x - 'A') & 0x1 ) ? 'A' : 'a') ;
            text[i] = x + offset;
        }
        /* text[i] is digit */
        else if(text[i] >= '0' && text[i] <= '9') {
            printf("%c is a number \n", text[i]);
            text[i] = ((text[i] - '0' + nkeyHash) % 10) + '0';
        }
        else
            printf("%c is an ascii character\n", text[i]);
    }
}

void trans (char* text, int textLength) {

}
