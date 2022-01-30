//
//  BaseChain.m
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//

#import "BaseChain.h"

@implementation BaseChain

/// 生成助记词
/// @param bits 助记词位数
/// @param language 助记词语言
/// @return 助记词字符串，以空格 ` ` 分割
+ (nullable NSString *)chain_generateMnemonicBits:(BIP39Bits)bits language:(BIP39Language)language{
    size_t digit = bip39_mnemonic_bits(bits);
    unsigned char dst[digit][20];
    bip39_generate_mnemonic(dst, bits, language);
    NSMutableString * __autoreleasing string = [NSMutableString string];
    for (int i = 0; i < digit; i++) {
        NSString * word = [NSString stringWithUTF8String:dst[i]];
        [string appendFormat:@"%@ ", word];
    }
    NSString * result = [string copy];
    return [result length] ? result : nil;
}

@end
