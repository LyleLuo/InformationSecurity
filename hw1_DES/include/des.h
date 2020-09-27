#pragma once
#include "bits_operation.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define DES_ENCRYPT 0
#define DES_DECRYPT 1

typedef struct
{
    // 执行permutation前的比特数
    int from_bits;
    // 执行permutation后的比特数
    int to_bits;
    int permutation_table[64];
} permutation_t;

/**
 * @brief 根据置换表 permutation_table，将 chunk 进行置换
 * @param perm 置换表，表中每个元素 perm[i] 为 e 表示对应位置 result[i] = chunk[e]
 * @param chunk 将被置换的数组
 * @return 置换后的数组
 */
uint64_t do_permutation(const permutation_t *perm, const uint64_t chunk);

uint64_t do_iter_and_switch(uint64_t key, const uint64_t chunk, int state);

/**
 * @brief 做 DES 的 S-Box 选择
 * @note S-Box 选择函数是 6 位转 4 位的变换。
 * 假设 Si=(abcdef)2，那么 n=(af)2 确定行号，m=(bcde)2 确定列号
 * @param chunk 二进制位数为 6 的 Feistel 轮函数分组
 * @return 二进制位数为 4 的选择后的分组
 */
uint64_t do_sbox(const int boxs, const uint64_t chunk);

uint64_t feistel(const uint64_t old_right, const uint64_t key);

void gernerate_subkey(uint64_t key, uint64_t subkey[]);

uint64_t _des_process(uint64_t input, uint64_t key, int state);

void des_encrypt(char * input, char * output, char key[8]);

void des_decrypt(char * input, char * output, char key[8]);

void generate_key(char key[8]);


extern const permutation_t PERM_IP;
extern const permutation_t PERM_IPINV;
extern const permutation_t PERM_E_EXTENSION;
extern const int S_BOX[8][4][16];
extern const permutation_t PERM_P;
extern const permutation_t PERM_PC1;
extern const permutation_t PERM_PC2;
extern const permutation_t PERM_REMOVE_PARITY;