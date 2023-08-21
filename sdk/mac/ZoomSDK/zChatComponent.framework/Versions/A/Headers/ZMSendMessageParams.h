//
//  ZMSendMessageParams.h
//  zChatUI
//
//  Created by Cain Zhou on 2022/9/26.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 Send Message Params
 Design pattern: adapter for avoid too many input params and version incompatibility for `sendText` method
 */

@interface ZMSendMessageParams : NSObject

// meeting chat
@property (nonatomic, assign) NSInteger meetMsgType;
@property (nonatomic, copy) NSString *meetDMReceiverId;
@property (nonatomic, assign) NSInteger meetDMReceiverNodeId;

@end

NS_ASSUME_NONNULL_END
