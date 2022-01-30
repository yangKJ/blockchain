//
//  wordlist.h
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//

#ifndef wordlist_h
#define wordlist_h

#include <stdio.h>

///
/// BIP39定义的单词表，https://github.com/bitcoin/bips/blob/master/bip-0039/bip-0039-wordlists.md

/// 助记词语言
typedef enum {
    english,
} BIP39Language;
struct words {
    size_t size; /// 单词数目
    const char ** lists; /// 单词列表
};
/// 获取单词表
/// @param language 单词语言
extern struct words word_lists(BIP39Language language);

/// 释放资源
extern void word_lists_free(struct words word);

#endif /* wordlist_h */
