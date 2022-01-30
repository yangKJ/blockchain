//
//  bip39.c
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//

#include "bip39.h"

#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sha256.h"

/// 获取助记词个数
size_t bip39_mnemonic_bits(BIP39Bits bits){
    switch (bits) {
        case m12:return 12;
        case m15:return 15;
        case m18:return 18;
        case m21:return 21;
        case m24:return 24;
    }
    return 0;
}

/// 生成随机数的回调函数
/// @param random 随机数
/// @param len 长度
void bip39_random(unsigned char * random, int len){
    int i, random_num;
    struct timeval tv;
    unsigned int seed_num;
    char seed_str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unsigned long seed_str_len = strlen(seed_str);
    gettimeofday(&tv, NULL);
    seed_num = (unsigned int)(tv.tv_sec + tv.tv_usec);
    srand(seed_num);
    for (i = 0; i < len; i++) {
        random_num = rand() % seed_str_len;
        random[i] = seed_str[random_num];
    }
}

/// 字符串转二进制，转十进制
/// @param str 待转字符串
/// @param cnt 二进制长度
int bip39_char_to_binary_to_decimalism(unsigned char * str, size_t cnt){
    char binary[cnt];
    for (int i = 0; i < cnt; i++) {
        if ((str[i] >> (i-1)) & (0x01 == 1)) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
    }
    return strtol(binary, NULL, 2);
}

/// 生成助记词
/// @param bits 助记词位数
/// @param language 助记词语言
void bip39_generate_mnemonic(unsigned char dst[][20], BIP39Bits bits, BIP39Language language){
    // 读取文件内容，助记词单词
    const struct words read = word_lists(language);
    
    // 生成指定位长度随机数
    BYTE random[bits];
    bip39_random(random, bits);
    
    // SHA256
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, random, strlen(random));
    sha256_final(&ctx, buf);
    
    // 拼接，取哈希之后的前4位
    BYTE checksum[4],append[bits + 4];
    strncpy(checksum, buf, 4);
    strcpy(append, random);
    strcat(append, checksum);
    
    // 按每11位切分`split`
    size_t cnt = 11;
    BYTE dividing[cnt];
    for (int i = 0; i < bits + 4; i+=cnt) {
        strncpy(dividing, append + i, cnt);
        int index = bip39_char_to_binary_to_decimalism(dividing, cnt);
        strcpy(dst[i/cnt], read.lists[index]);
    }
    
    word_lists_free(read);
}
