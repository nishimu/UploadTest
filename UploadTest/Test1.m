//
//  Test1.m
//  UploadTest
//
//  Created by 西村 俊夫 on 2012/10/09.
//  Copyright (c) 2012年 Can-I Systems. All rights reserved.
//

#import "Test1.h"
#import "server.h"
#import "NSStream+getStreamsToHost.h"

@implementation Test1 {
    NSInputStream* inputStream;
    NSOutputStream* outputStream;
    dispatch_queue_t taskQ;
    NSDate* start;
    NSMutableData* sendData;
}

-(id)initWithDelegate:(id)delegate {
    self = [super init];
    if (self) {
        self.delegate = delegate;
    }
    return self;
}
-(void)test {
    taskQ = dispatch_queue_create("com.canisystems.uploadtest.sendData", DISPATCH_QUEUE_SERIAL);
    const char sample[] = {SAMPLE_SEND_DATA};
    sendData = [NSMutableData new];
    //    NSUInteger size = 512;
    NSUInteger size = BUF_LENGTH;
    while (size > [sendData length]) {
        if (size - [sendData length] < sizeof(sample)) {
            [sendData appendBytes:sample length:size - [sendData length]];
        } else {
            [sendData appendBytes:sample length:sizeof(sample)];
        }
    }
    start = [NSDate date];
    NSInputStream* instream;
    NSOutputStream* outstream;
    [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"test" waitUntilDone:NO];
    if (![NSStream getStreamsToHostNamed:SERVER_IP_ADDRESS port:SERVER_PORT inputStream:&instream outputStream:&outstream]) {
        [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"openError" waitUntilDone:NO];
    } else {
        inputStream = instream;
        outputStream = outstream;
        [inputStream setDelegate:self];
        [outputStream setDelegate:self];
        
        [inputStream scheduleInRunLoop:[NSRunLoop currentRunLoop]
                               forMode:NSDefaultRunLoopMode];
        [outputStream scheduleInRunLoop:[NSRunLoop currentRunLoop]
                                forMode:NSDefaultRunLoopMode];
        
        [outputStream open];
        [inputStream open];
    }

}
- (void)stream:(NSStream *)stream handleEvent:(NSStreamEvent)eventCode {
    if (eventCode & NSStreamEventOpenCompleted) {
        [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"NSStreamEventOpenCompleted" waitUntilDone:NO];
    }
    if (eventCode & NSStreamEventEndEncountered) {
        [self close];
        [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"NSStreamEventEndEncountered"
                                     waitUntilDone:NO];
        return;
    }
    if (eventCode & NSStreamEventErrorOccurred) {
        [self close];
        [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"NSStreamEventEndEncountered"
                                     waitUntilDone:NO];
        return;
    }
    
    if (eventCode & NSStreamEventHasBytesAvailable) {
        // do nothing
    }
    if (eventCode & NSStreamEventHasSpaceAvailable) {
        NSDate* now = [NSDate date];
        if ([now timeIntervalSinceDate:start] >= TEST_DURATION) {
            dispatch_async(taskQ,
                           ^ {
                               uint8_t endmark = ENDMARK;
                               [outputStream write:&endmark maxLength:sizeof(uint8_t)];
                           });
        } else {
            dispatch_async(taskQ,
                           ^ {
                               [outputStream write:[sendData bytes] maxLength:[sendData length]];
                           });
        }
    }
}

- (void) close {
    [self.delegate performSelectorOnMainThread:@selector(showMessage:) withObject:@"close" waitUntilDone:NO];
    [inputStream close];
    [inputStream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [inputStream setDelegate:nil];
    inputStream = nil;
    [outputStream close];
    [outputStream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [outputStream setDelegate:nil];
    outputStream = nil;
//    dispatch_release(taskQ);
}

@end
