#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "rsa.h"

int main() {
    mpz_t n, e, d;
    mpz_init(n);
    mpz_init(e);
    mpz_init(d);
    generate_key(1024, n, e, d);

    char * message = malloc(100);
    strcpy(message, "Hello, world!\n");
    rsa_encrypt(n, e, 1024/8, &message);
    rsa_decrype(n, d, 1024/8, &message);
    printf("%s", message);

    free(message);
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
}