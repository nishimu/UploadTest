//
//  NSStream+getStreamsToHost.h
//  RBBSpeedTest
//
//  Created by 西村 俊夫 on 12/05/23.
//  Copyright (c) 2012年 CAN-I Systems Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSStream (getStreamsToHost)
+ (BOOL)getStreamsToHostNamed:(NSString *)hostName
                         port:(NSInteger)port
                  inputStream:(out NSInputStream **)inputStreamPtr
                 outputStream:(out NSOutputStream **)outputStreamPtr;

@end
