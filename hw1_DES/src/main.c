#include <stdio.h>
#include "des.h"

int main() {
    
}

// test 1
// int main(int argc,char **argv) {
//     char key[9], buffer[1000];;
//     key[8] = 0;
//     generate_key(key);
//     char * text = "Hello, world!";
//     des_encrypt(text, buffer, key);
//     des_decrypt(buffer, buffer, key);
//     fprintf(stdout, "%s\n", buffer);
// } 

// test 2
// int main(int argc,char **argv) {
//     char key[9], buffer[1000];;
//     key[8] = 0;
//     for (int i = 0; i < 4; ++i) {
//         key[i] = 0xe0;
//     }
//     for (int i = 4; i < 8; ++i) {
//         key[i] = 0xf1;
//     }

//     FILE *fp_c = NULL;
//     fp_c = fopen("/home/luowle/homework/InformationSecurity/hw1_DES/test/ciphertext", "r"); 
//     fscanf(fp_c, "%s", buffer);

//     des_decrypt(buffer, buffer, key);
//     fprintf(stdout, "%s", buffer);
// } 


