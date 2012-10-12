//
//  Test2.h
//  UploadTest
//
//  Created by 西村 俊夫 on 2012/10/10.
//  Copyright (c) 2012年 Can-I Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TestDelegate.h"

@interface Test2 : NSObject<NSStreamDelegate>
-(id)initWithDelegate:(id)delegate;
-(void) test;
@property (unsafe_unretained, nonatomic) NSObject<TestDelegate>* delegate;
@end
