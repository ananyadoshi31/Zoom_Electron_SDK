//
//  ZMReactionEmojiInfo.h
//  ZCommonUI
//
//  Created by groot.ding on 21/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMReactionEmojiInfo : NSObject

@property (nonatomic,copy)    NSString* emojiString;
@property (nonatomic,assign)  NSInteger count;
@property (nonatomic,assign)  NSInteger firstTimeStamp;
@property (nonatomic,assign)  BOOL isContainMe;

- (instancetype)initWithEmojiString:(NSString*)emojiString count:(NSInteger)count isContainMe:(BOOL)isContainMe firstTimestamp:(NSInteger)firstTimestamp;

@end

NS_ASSUME_NONNULL_END
