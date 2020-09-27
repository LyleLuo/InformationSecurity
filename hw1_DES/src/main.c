#include <stdio.h>
#include "des.h"
 
int main(int argc,char **argv) {
    char key[8];
    generate_key(key);
    char * text = "hello, world!";
    char buffer[1000];
    des_encrypt(text, buffer, key);
    des_decrypt(buffer, buffer, key);
    return 0;
} 