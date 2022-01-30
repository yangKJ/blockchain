//
//  bip39.h
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//  助记词相关

#ifndef bip39_h
#define bip39_h

#include <stdio.h>
#include "wordlist.h"

/// 助记词秘钥生成器网站，https://iancoleman.io/bip39/
/// 助记词生成过程：
/// 举12位助记词例子，
/// 生成一个128位随机数，再加上对随机数校验4位，得到132位的数，
/// 然后按每11位做切分，这样就有12个二进制数，
/// 然后用每个数去查BIP39定义的单词表，这样就得到12个助记单词

/// 助记词位数
enum BIP39Bits {
    m12 = 128,
    m15 = 160,
    m18 = 192,
    m21 = 224,
    m24 = 256,
};
typedef enum BIP39Bits BIP39Bits;

/// 获取助记词个数
extern size_t bip39_mnemonic_bits(BIP39Bits bits);

/// 生成随机数的回调函数
/// @param random 随机数
/// @param len 长度
extern void bip39_random(unsigned char * random, int len);

/// 生成助记词
/// @param bits 助记词位数
/// @param language 助记词语言
extern void bip39_generate_mnemonic(unsigned char dst[][20],
                                    BIP39Bits bits,
                                    BIP39Language language);



#endif /* bip39_h */
