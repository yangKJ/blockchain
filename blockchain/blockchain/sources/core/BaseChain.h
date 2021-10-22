//
//  BaseChain.h
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//  底层公共链

#import <Foundation/Foundation.h>

#include "bip39.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseChain : NSObject

/// 生成助记词
/// @param bits 助记词位数
/// @param language 助记词语言
/// @return 助记词字符串，以空格 ` ` 分割
+ (nullable NSString *)chain_generateMnemonicBits:(BIP39Bits)bits
                                         language:(BIP39Language)language NS_REQUIRES_SUPER;



@end

NS_ASSUME_NONNULL_END
