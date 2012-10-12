//
//  NSStream+getStreamsToHost.m
//  RBBSpeedTest
//
//  Created by 西村 俊夫 on 12/05/23.
//  Copyright (c) 2012年 CAN-I Systems Co., Ltd. All rights reserved.
//

#import "NSStream+getStreamsToHost.h"

@implementation NSStream (getStreamsToHost)
+ (BOOL)getStreamsToHostNamed:(NSString *)hostName
                                           port:(NSInteger)port
                                    inputStream:(out NSInputStream **)inputStreamPtr
                                   outputStream:(out NSOutputStream **)outputStreamPtr
{
    CFReadStreamRef     readStream;
    CFWriteStreamRef    writeStream;
    
    if (!(hostName != nil)) return NO;
    if (!( (port > 0) && (port < 65536) )) return NO;
    if (!( (inputStreamPtr != NULL) || (outputStreamPtr != NULL) )) return NO;
    
    readStream = NULL;
    writeStream = NULL;
    
    CFStreamCreatePairWithSocketToHost(
                                       NULL,
                                       (__bridge CFStringRef) hostName,
                                       port,
                                       ((inputStreamPtr  != NULL) ? &readStream : NULL),
                                       ((outputStreamPtr != NULL) ? &writeStream : NULL)
                                       );
    
    if (inputStreamPtr != NULL) {
        *inputStreamPtr  = CFBridgingRelease(readStream);
    }
    if (outputStreamPtr != NULL) {
        *outputStreamPtr = CFBridgingRelease(writeStream);
    }
    return YES;
}


@end
