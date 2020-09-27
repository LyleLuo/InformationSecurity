#pragma once
#include <stdint.h>

uint64_t get_bit(const uint64_t chunk, const int pos);
void set_bit(uint64_t *chunk, const int pos, const uint64_t state);
uint64_t loop_right_shift(uint64_t data, int len);
void uint64_to_char_str(uint64_t input, char str[8]);
uint64_t char_str_to_uint64(char str[8]);