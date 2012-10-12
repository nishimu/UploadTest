//
//  NetworkThread.h
//  UploadTest
//
//  Created by 西村 俊夫 on 2012/10/09.
//  Copyright (c) 2012年 Can-I Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetworkThread : NSObject
+ (NSThread *)networkThread;
+ (void)networkThreadMain:(id)unused;

@end
