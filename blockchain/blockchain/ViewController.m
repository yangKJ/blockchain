//
//  ViewController.m
//  blockchain
//
//  Created by 77。 on 2021/10/1.
//

#import "ViewController.h"

#import "ETHBlockChain.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSString * mnemonic = [ETHBlockChain chain_generateMnemonicBits:m12 language:english];
    
    NSLog(@"--- \n%@", mnemonic);
}

@end
