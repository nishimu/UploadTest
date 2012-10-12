//
//  NetworkThread.m
//  RBBSpeedTest
//
//  Created by 西村 俊夫 on 2012/09/12.
//  Copyright (c) 2012年 IID Co., Ltd. All rights reserved.
//

#import "NetworkThread.h"

@implementation NetworkThread
+ (NSThread *)networkThread {
    static NSThread *networkThread = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        networkThread =
        [[NSThread alloc] initWithTarget:self
                                selector:@selector(networkThreadMain:)
                                  object:nil];
        [networkThread start];
    });
    
    return networkThread;
}

+ (void)networkThreadMain:(id)unused {
    do {
        @autoreleasepool {
            [[NSRunLoop currentRunLoop] run];
        }
    } while (YES);
}

@end
