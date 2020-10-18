#pragma once
#include <gmp.h>

void generate_key(int k, mpz_t n, mpz_t e, mpz_t d);

void rsa_encrypt(mpz_t key_n, mpz_t public_key_e, int key_len, char ** M);

void rsa_decrype(mpz_t key_n, mpz_t private_key_d, int key_len, char ** C);

void os2ip(char * str, int len, mpz_t result);

void i2osp(mpz_t x, int len, char * result);

void rsa_adp_aep(mpz_t key_n, mpz_t e, mpz_t m, mpz_t result);