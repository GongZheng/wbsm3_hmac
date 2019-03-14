#include<stdio.h>
#include "sm3.h"

void dump(const uint8_t *li, int len)
{
    int line_ctrl = 16;
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%02X", (*li++));
        if ((i + 1) % line_ctrl == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
}

int main() {
    unsigned char *msg;
    msg = "Hello World!";
    unsigned char digest[SM3_DIGEST_LENGTH];

    sm3(msg, strlen(msg), digest);

    dump(digest,sizeof(digest));
    
    printf("\n");

        return 0;
}