#include<stdio.h>
#include "sm3.h"

int main() {
    unsigned char *msg;
    msg = "Hello World!";
    unsigned char digest[SM3_DIGEST_LENGTH];

    sm3(msg, strlen(msg), digest);

    return 0;
}