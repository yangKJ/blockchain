//
//  ETHBlockChain.m
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//

#import "ETHBlockChain.h"

@implementation ETHBlockChain

/// 生成助记词
/// @param bits 助记词位数
/// @param language 助记词语言
/// @return 助记词字符串，以空格 ` ` 分割
+ (nullable NSString *)chain_generateMnemonicBits:(BIP39Bits)bits language:(BIP39Language)language{
    return [super chain_generateMnemonicBits:bits language:language];
}

@end
