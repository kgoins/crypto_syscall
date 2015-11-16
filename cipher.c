#include "cipher.h"

int cipher (char* text, int lkey, int nkey) {   
    
    int textLength = processInput(text);

    /* run encryption algorithms */
    /* sub(text, lkey, nkey, textLength); */
    trans(text, textLength);

    return textLength;
}

int processInput (char* text) {
    int textLength = 0;

    /* calculate text length */
    while(text[textLength] != '\0') {
        ++textLength;
    }

    /* account for ending null terminator */
    textLength += 1;

    /* truncate string */
    if(textLength > CIPHER_TEXT_MAX) {
        textLength = CIPHER_TEXT_MAX;
        text[textLength] = '\0';
    }

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
            x = (text[i] - 'A' + lkeyHash) % 26;

            if (decrypt)
                offset = ((x-'A') & 0x1) ? 'A':'a';
            else
                offset = ((x-'A') & 0x1) ? 'a':'A';

            text[i] = x + offset;
        }
        /* text[i] is lower case letter */
        else if(text[i] >= 'a' && text[i] <= 'z') {
            x = (text[i] - 'a' + lkeyHash) % 26;
            offset = (decrypt) ? 
                ( ( (x - 'A') & 0x1 ) ? 'a' : 'A' ) :
                ( ( (x - 'A') & 0x1 ) ? 'A' : 'a') ;
            text[i] = x + offset;
        }
        /* text[i] is digit */
        else if(text[i] >= '0' && text[i] <= '9') {
            text[i] = ((text[i] - '0' + nkeyHash) % 10) + '0';
        }
        else
            continue;
    }
}

void trans (char* text, int textLength) {
    char temp; int i;
    int lastQuad = textLength % 4;

    /* process the text up to the last quad */
    for (i = 0; i < (textLength - lastQuad); i+=4) {
        temp = text[i];
        text[i] = text[i+2];
        text[i+2] = temp;

        temp = text[i+1];
        text[i+1] = text[i+3];
        text[i+3] = temp;
    } /* i holds the start of the last quad */

    /* process the last quad if exists */
    if (lastQuad !=0) 
        switch(lastQuad) {
            case 1:
                break;

            case 2:
                temp = text[i];
                text[i] = text[i+1];
                text[i+1] = temp;
                break;

            case 3:
                temp = text[i];
                text[i] = text[i+2];
                text[i+2] = temp;
                break;
        }
}
