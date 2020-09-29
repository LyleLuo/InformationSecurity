# C语言实现DES对称算法
## 使用方法
```sh
cd hw1_DES && make
cd bin
./des
```

## 文件结构
```
hw1_DES
    |
    --- README.md
    |
    --- include
    |   |
    |   --- bits_operation.h
    |   |
    |   --- des.h
    |
    --- src
        |   |
    |   --- bits_operation.c
    |   |
    |   --- des.c
    |   |
    |   --- main.c
    |
    --- bin
        |
        ---des
```

## 主要函数的调用关系
```c
main()
    |
    --- generate_key()
    |
    --- des_encrypt()
    |   |
    |   --- _des_process(DES_ENCRYPT)
    |       |
    |       --- do_permutation(&PERM_IP)
    |       |
    |       --- do_iter_and_switch()
    |       |   |
    |       |   --- gernerate_subkey()
    |       |   |
    |       |   --- feistel()
    |       |
    |       --- do_permutation(&PERM_IPINV)
    |       
    --- des_decrypt()
        |
        --- _des_process(DES_DECRYPT)

```

## 文件内容
**各个函数的使用方法都在头文件有清楚的注释，此处不再重复放代码**  
-  bit_operation.h/c 本项目使用的是 **uint64_t** 来储存一个64位的块（值得注意的是，该库的实现是将64位无符号整数的最右边的位置当作第一位，符合我们对2进制整数的认识）。该文件实现了直接对一个 uint64_t 进行 get_bit()，set_bit()，循环移位，uint64_t 和 char[8]之间转换的函数。
- des.h/c 该文件实现了所有DES算法所用到的操作。
- main.c 该文件使用了DES算法

## 测试
### 使用自己写的函数，使用随机生成的密钥进行加密解密，主函数如下所示：
```c
#include <stdio.h>
#include "des.h"
 
int main(int argc,char **argv) {
    char key[9], buffer[1000];;
    key[8] = 0;
    generate_key(key);
    char * text = "Hello, world!";
    des_encrypt(text, buffer, key);
    des_decrypt(buffer, buffer, key);
    fprintf(stdout, "%s\n", buffer);
} 
```
结果如下所示：
```sh
[luowle@VM_0_4_centos hw1_DES]$ ./bin/des 
Hello, world!
```

### 使用 openssl 验证。方法：使用 openssl 进行加密，再用自己写的版本进行解密。
由于加密解密是对应的，上一步已经验证了自己写的库可以解密自己加密的密文。如果自己写的解密函数可以解密 openssl 加密的密文，就可以说明自己写的加密函数也是正确的。主函数如下所示：
```c
int main(int argc,char **argv) {
    char key[9], buffer[1000];;
    key[8] = 0;
    for (int i = 0; i < 4; ++i) {
        key[i] = 0xe0;
    }
    for (int i = 4; i < 8; ++i) {
        key[i] = 0xf1;
    }

    FILE *fp_c = NULL;
    fp_c = fopen("/home/luowle/homework/InformationSecurity/hw1_DES/test/ciphertext", "r"); 
    fscanf(fp_c, "%s", buffer);

    des_decrypt(buffer, buffer, key);
    fprintf(stdout, "%s", buffer);
} 
```
结果如下所示，可以看见自己写的解密函数可以解密密文。因此该库的正确性是可以保证的。

```
[luowle@VM_0_4_centos test]$ cat input 
Hello, world!
[luowle@VM_0_4_centos test]$ openssl enc -des-ecb -K e0e0e0e0f1f1f1f1 -in input -out ciphertext
[luowle@VM_0_4_centos test]$ ./../bin/des 
Hello, world!
```

