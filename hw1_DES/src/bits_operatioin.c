#include "bits_operation.h"

uint64_t get_bit(const uint64_t chunk, const int pos) {
    uint64_t result = chunk >> pos & (uint64_t)1;
    return result;
}

void set_bit(uint64_t *chunk, const int pos, const uint64_t state) {
    if (state) {
        *chunk = *chunk | (state << pos);
    }
    else {
        *chunk = *chunk & (~((uint64_t)1 << pos));
    }
}

uint64_t loop_right_shift(uint64_t data, int len) {
    uint64_t temp = data & 1;
    data = data >> 1;
    data |= temp << (len - 1);
    return data;
}

void uint64_to_char_str(uint64_t input, char str[8]) {
    for (int i = 0; i < 8; ++i) {
        str[i] &= 0;
    }
    for (int i = 0; i < 64; ++i) {
        int state = get_bit(input, i);
        str[i / 8] |= state << (7 - (i % 8));
    }
}

uint64_t char_str_to_uint64(char str[8]) {
    uint64_t result = 0;
    for (int i = 0; i < 64; ++i) {
        uint64_t ch = str[i / 8];
        uint64_t state = (ch >> (7 - (i % 8))) & 1;
        set_bit(&result, i, state);
    }
    return result;
}
