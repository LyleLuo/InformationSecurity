#include <stdio.h>
#include "md5.h"
#include <string.h>

int main() {
    char * s = "hello, world!";
    uint8_t buffer[1000];
    MD5(s, strlen(s), buffer);
    for (int i = 0; i < 16; ++i) {
        printf("%x", (uint32_t)buffer[i]);
    }
    printf("\n");
}