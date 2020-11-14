#pragma once

#include <stdint.h>

typedef struct MD5_CV
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
} CV;

typedef struct Message_Block
{
    uint32_t x[16];
} MB;

#define F(b, c, d) ((b & c) | (~b & d))
#define G(b, c, d) ((b & d) | (c & ~d))
#define H(b, c, d) (b ^ c ^ d)
#define I(b, c, d) (c ^ (b | ~d))
#define CLS(x, s) ((x >> (32 - s)) | (x << s))

void uint32_reverse(uint32_t * a);

void MD5(char *message, uint64_t message_len, uint8_t *result);

CV HMD5(CV cv, MB mb);
